return {
	type = "method",
	description = [[Damages the actor.]],
	arguments = {
		{ name = "damage", type = "number", description = "The amount of damage to apply." },
		{ name = "flipDifficultyScale", type = "boolean" },
		{ name = "scaleWithDifficulty", type = "boolean", description = "Apply difficulty scaling to the damage." },
		{ name = "takeHealth", type = "boolean" },
	},
	valuetype = "boolean",
}