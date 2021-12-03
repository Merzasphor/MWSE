return {
	type = "function",
	description = [[Fetches the core game object for a given skill ID.]],
	arguments = {
		{ name = "id", type = "number", description = "Maps to [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) constants." }
	},
	returns = "skill",
	valuetype = "tes3skill",
}