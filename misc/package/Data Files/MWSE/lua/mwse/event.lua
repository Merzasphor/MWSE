local this = {}

local generalEvents = {}

local filteredEvents = {}

local function getEventTable(eventType, filter)
	if (filter == nil) then
		if (generalEvents[eventType] == nil) then
			generalEvents[eventType] = {}
		end
		return generalEvents[eventType]
	else
		if (filteredEvents[eventType] == nil) then
			filteredEvents[eventType] = {}
		end
		if (filteredEvents[eventType][filter] == nil) then
			filteredEvents[eventType][filter] = {}
		end
		return filteredEvents[eventType][filter]
	end
end

function this.register(eventType, callback, options)
	-- Validate event type.
	if (type(eventType) ~= "string" or eventType == "") then
		return error("event.register: Event type must be a valid string.")
	end

	-- Validate callback.
	if (type(callback) ~= "function") then
		return error("event.register: Event callback must be a valid string.")
	end

	-- Make sure options is an empty table if nothing else.
	local options = options or {}

	-- If 'doOnce' was set, wrap with a call to unregister.
	if options.doOnce then
		local originalCallback = callback
		callback = function (e)
			originalCallback(e)
			this.unregister(eventType, callback, options)
		end
	end

	-- Make sure that the event isn't already registered.
	local callbacks = getEventTable(eventType, options.filter)
	local found = table.find(callbacks, callback)
	if (found == nil) then
		table.insert(callbacks, callback)
	else
		print("event.register: Attempted to register same '" .. eventType .. "' event callback twice.")
		print(debug.traceback())
	end
end

function this.unregister(eventType, callback, options)
	-- Validate event type.
	if (type(eventType) ~= "string" or eventType == "") then
		return error("event.unregister: Event type must be a valid string.")
	end

	-- Validate callback.
	if (type(callback) ~= "function") then
		return error("event.unregister: Event callback must be a valid function.")
	end

	-- Make sure options is an empty table if nothing else.
	local options = options or {}

	local callbacks = getEventTable(eventType, options.filter)
	local removed = table.removevalue(callbacks, callback)
	-- if (not removed) then
		-- print("event.register: Attempted to unregister '" .. eventType .. "' event callback that wasn't registered.")
		-- print(debug.traceback())
	-- end
end

function this.clear(eventType, filter)
	if (filter == nil) then
		-- Clear out general events of this type.
		generalEvents[eventType] = nil
	else
		if (eventType == nil) then
			-- No event supplied, so let's clear out all events for this filter.
			for k, v in pairs(filteredEvents) do
				v[filter] = nil
			end
		elseif (filteredEvents[eventType] ~= nil) then
			-- Clear out a specific event type/filter combo.
			filteredEvents[eventType][filter] = nil
		end
	end
end

function this.trigger(eventType, payload, options)
	-- Make sure params are an empty table if nothing else.
	local payload = payload or {}
	local options = options or {}

	payload.eventType = eventType
	payload.eventFilter = options.filter

	local callbacks = getEventTable(eventType, options.filter)
	for _, callback in pairs(callbacks) do
		local status, result = pcall(callback, payload)
		if (status == false) then
			mwse.log("Error in event callback: %s\n%s", result, debug.traceback())
			result = nil
		end

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

	-- At this point if we have a filter, we've run through the filtered events.
	-- Fire off the unfiltered events too.
	if (options.filter ~= nil) then
		this.trigger(eventType, payload)
	end

	return payload
end

return this