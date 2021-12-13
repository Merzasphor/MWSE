return {
	type = "method",
	description = [[Returns the total progress needed to progress the skill to the next level.]],
	arguments = {
		{ name = "skill", type = "number", description = "The skill index to check." },
	},
	returns = {
		{ name = "progressNeeded", type = "number" },
	}
}