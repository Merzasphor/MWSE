return {
	type = "method",
	description = [[Fetches the current value of a skill with a given index. This converts to the limited options available for creatures.]],
	arguments = {
		{ name = "skillId", type = "number", description = "The index of the skill statistic's value to fetch." },
	},
	valuetype = "number",
}