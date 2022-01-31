-- Show the id when the player activates an object.
local function myOnActivateCallback(e)
	if (e.activator == tes3.player) then
		tes3.messageBox({ message = "Activated " .. e.target.object.id })
	end
end
event.register(tes3.event.activate, myOnActivateCallback)