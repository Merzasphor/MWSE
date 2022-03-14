
local function printNames(e)
	local skillTypeNames = {
		[0] = "Major",
		[1] = "Minor",
		[2] = "Miscellaneous"
	}

	for _, skillId in pairs(tes3.skill) do
		local skillStat = tes3.mobilePlayer:getSkillStatistic(skillId)
		local name = tes3.getSkillName(skillId)
		local typeName = skillTypeNames[skillStat.type]

		tes3ui.log("%s, type: %s skill", name, typeName)
	end

	tes3.messageBox("Done! Open the console to see the result.")
end

event.register(tes3.event.keyDown, printNames, { filter = tes3.scanCode.u })
