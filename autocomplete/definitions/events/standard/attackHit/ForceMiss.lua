local function onAttackHitCallback(e)
	-- Set damage to zero to convert the physical hit to a miss.
	tes3.messageBox("Somehow it missed!")
	e.mobile.actionData.physicalDamage = 0
end
event.register(tes3.event.attackHit, onAttackHitCallback)