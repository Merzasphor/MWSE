return {
	type = "method",
	description = [[Fetches the statistic object of a skill with a given index. This converts to the limited options available for creatures.]],
	arguments = {
		{ name = "skillId", type = "number", description = "The index of the skill statistic to fetch." },
	},
	valuetype = "tes3skillStatistic",
}