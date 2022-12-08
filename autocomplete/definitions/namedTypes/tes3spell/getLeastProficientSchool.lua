return {
	type = "method",
	description = [[Returns the school of the least proficient effect on the spell, for a given actor.]],
	arguments = {
		{ name = "actor", type = "tes3mobileActor|tes3reference|tes3npc|tes3npcInstance", optional = false, description = "The actor to calculate for. A mobile actor is preferred, as passing only a `tes3npc` will not use up to date skill information." },
	},
	returns = {
		{ name = "schoolID", type = "number|nil", description = "The least proficient school ID (from [`tes3.magicSchool`](https://mwse.github.io/MWSE/references/magic-schools/) table), or `nil` if the spell has no valid effects." },
	}
}
