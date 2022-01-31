-- The following code can be tested in-game by pressing Alt + l or Alt + k

event.register(tes3.event.keyDown, function(e)
	if e.isAltDown then
		tes3.messageBox("mwscript.explodeSpell")
		mwscript.explodeSpell({
			reference = tes3.game.playerTarget,
			spell = "proj_trap_spell"
		})
	end
end, { filter = tes3.scanCode.l })

event.register(tes3.event.keyDown, function(e)
	if e.isAltDown then
		tes3.messageBox("tes3.cast")
		-- This will behave the same as will mwscript.explodeSpell()
		tes3.cast({
			target = tes3.game.playerTarget,
			reference = tes3.game.playerTarget,
			spell = "proj_trap_spell",
		})
	end
end, { filter = tes3.scanCode.k })
