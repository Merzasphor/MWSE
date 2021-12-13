return {
	type = "method",
	description = [[Increments the player's skill to the next level, while respecting all level up mechanics.]],
	arguments = {
		{ name = "skill", type = "number", description = "The skill index to increase." },
	},
	returns = {
		{ name = "newLevel", type = "number" },
	}
}