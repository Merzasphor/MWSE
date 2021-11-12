
local function myOnActivateCallback(e)
	-- We only care if the PC is activating something.
	if (e.activator ~= tes3.player) then
		return
	end

	-- If the player targets an NPC, block the activation.
	if (e.target.object.objectType == tes3.objectType.npc) then
		return false
	end
end
event.register("activate", myOnActivateCallback)
