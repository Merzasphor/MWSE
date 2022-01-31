local function myOnAttackCallback(e)
	-- Someone other than the player is attacking.
	if (e.reference ~= tes3.player) then
		return
	end

	-- We hit someone!
	if (e.targetReference ~= nil) then
		tes3.messageBox("You hit %s!", e.targetReference.object.name or e.targetReference.object.id)
	end
end
event.register(tes3.event.attack, myOnAttackCallback)