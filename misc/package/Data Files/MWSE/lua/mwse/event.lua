local this = {}

local generalEvents = {}
local filteredEvents = {}

function getEventTable(eventType, filter)
	if (filter) then
		if (filteredEvents[eventType] == nil) then
			filteredEvents[eventType] = {}
		end
		if (filteredEvents[eventType][filter] == nil) then
			filteredEvents[eventType][filter] = {}
		end
		return filteredEvents[eventType][filter]
	else
		if (generalEvents[eventType] == nil) then
			generalEvents[eventType] = {}
		end
		return generalEvents[eventType]
	end
end

function this.register(eventType, callback, filter)
	-- Validate event type.
	if (type(eventType) ~= "string" or eventType == "") then
		return error("event.register: Event type must be a valid string.")
	end

	-- Validate callback.
	if (type(callback) ~= "function") then
		return error("event.register: Event callback must be a valid string.")
	end

	local callbacks = getEventTable(eventType, filter)
	table.insert(callbacks, callback)
end

function this.unregister(eventType, callback, filter)
	-- Validate event type.
	if (type(eventType) ~= "string" or eventType == "") then
		return error("event.unregister: Event type must be a valid string.")
	end

	-- Validate callback.
	if (type(callback) ~= "function") then
		return error("event.unregister: Event callback must be a valid string.")
	end

	local callbacks = getEventTable(eventType, filter)
	table.remove(callbacks, callback)
end

function this.unregisterFilter(filter)
	for event, filters in pairs(filteredEvents) do
		filters[filter] = nil
	end
end

function this.trigger(eventType, payload, filter)
	if (not payload) then
		payload = {}
	end

	payload.eventType = eventType

	local callbacks = getEventTable(eventType)
	for _, callback in pairs(callbacks) do
		local result = callback(payload)
		if (result) then
			return result
		end
	end
	
	if (filter) then
		local filteredCallbacks = getEventTable(eventType, filter)
		for _, callback in pairs(callbacks) do
			local result = callback(payload)
			if (result) then
				return result
			end
		end
	end

	return nil
end

return this