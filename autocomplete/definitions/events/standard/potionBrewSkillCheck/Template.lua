local function brewSkillCheck(e)
	local player = tes3.mobilePlayer
	local x = player.alchemy.current + 0.1 * player.intelligence.current + 0.1 * player.luck.current

	local roll = math.floor(100 * math.random())
	if (roll <= x) then
		local fPotionStrengthMult = tes3.findGMST(tes3.gmst.fPotionStrengthMult).value
		e.potionStrength = fPotionStrengthMult * e.mortar.quality * x
		e.success = true
	else
		e.potionStrength = -1
		e.success = false
	end
end

event.register("potionBrewSkillCheck", brewSkillCheck)