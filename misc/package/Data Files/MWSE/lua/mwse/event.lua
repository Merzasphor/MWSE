local this = {}

local generalEvents = {}

function getEventTable(eventType)
	if (generalEvents[eventType] == nil) then
		generalEvents[eventType] = {}
	end
	return generalEvents[eventType]
end

function this.register(eventType, callback)
	-- Validate event type.
	if (type(eventType) ~= "string" or eventType == "") then
		return error("event.register: Event type must be a valid string.")
	end

	-- Validate callback.
	if (type(callback) ~= "function") then
		return error("event.register: Event callback must be a valid string.")
	end

	-- Make sure that the event isn't already registered.
	local callbacks = getEventTable(eventType)
	local found = table.find(callbacks, callback)
	if (found == nil) then
		table.insert(callbacks, callback)
	else
		print("event.register: Attempted to register same '" .. eventType .. "' event callback twice.")
		print(debug.traceback())
	end
end

function this.unregister(eventType, callback)
	-- Validate event type.
	if (type(eventType) ~= "string" or eventType == "") then
		return error("event.unregister: Event type must be a valid string.")
	end

	-- Validate callback.
	if (type(callback) ~= "function") then
		return error("event.unregister: Event callback must be a valid function.")
	end

	local callbacks = getEventTable(eventType)
	if (not table.removevalue(callbacks, callback)) then
		print("event.register: Attempted to unregister '" .. eventType .. "' event callback that wasn't registered.")
		print(debug.traceback())
	end
end

function this.clear(eventType)
	generalEvents[eventType] = nil;
end

function this.trigger(eventType, payload)
	if (payload == nil) then
		payload = {}
	end

	payload.eventType = eventType

	local callbacks = getEventTable(eventType)
	for _, callback in pairs(callbacks) do
		local result = callback(payload)

		-- Returning non-nil from the callback claims/blocks the event.
		if (result ~= nil) then
			payload.claim = true
			payload.block = true
		end

		-- If the event is claimed, do not excute any further events.
		if (payload.claim) then
			return payload
		end
	end

	return payload
end

return this