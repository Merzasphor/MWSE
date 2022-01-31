local function OnSpellFailed(e)

	local skill = tes3.magicSchoolSkill[e.expGainSchool] -- Note: e.expGainSchool is a value in tes3.magicSchool constants table

	tes3.mobilePlayer:exerciseSkill(skill, 100)
end

event.register(tes3.event.spellCastedFailure, OnSpellFailed)
