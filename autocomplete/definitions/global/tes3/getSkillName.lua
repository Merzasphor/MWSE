return {
	type = "function",
	description = [[Returns the identifying name of a skill for a given numerical, 0-based index. E.g. "Enchant".]],
	arguments = {
		{ name = "skillId", type = "number", description = "Maps to [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) enumeration." }
	},
	returns = {{ name = "name", type = "string" }},
}