---@param e bodyPartAssignedEventData
local function baldIsBeautiful(e)
	if (e.index == tes3.activeBodyPart.hair) then
		-- Returning false from this event will
		-- block the assignment of the body part.
		return false
	end
end
event.register(tes3.event.bodyPartAssigned, baldIsBeautiful)