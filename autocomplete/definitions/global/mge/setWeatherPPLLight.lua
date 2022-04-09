return {
	type = "function",
	description = [[Sets light multipliers used in per-pixel lighting for a specific weather. `sunMultiplier` affects sunlight, while `ambientMultiplier` affects ambient lighting.]],
	arguments = {
		{ name = "weatherID", type = "number", description = "Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table." },
		{ name = "sunMultiplier", type = "number" },
		{ name = "ambientMultiplier", type = "number" }
	},
	returns = {{ name = "result", type = "number" }},
}