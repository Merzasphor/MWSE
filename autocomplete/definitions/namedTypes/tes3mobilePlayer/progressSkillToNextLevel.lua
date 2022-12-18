return {
	type = "method",
	description = [[Increments the player's skill to the next level, while respecting all level up mechanics.]],
	arguments = {
		{ name = "skill", type = "integer", description = "The skill index to increase. Maps to values from [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) table." },
	},
	returns = {
		{ name = "newLevel", type = "integer" },
	}
}