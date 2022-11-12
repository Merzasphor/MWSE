return {
	type = "function",
	description = [[Fetches the core game Magic Effect object for a given ID. Can return custom magic effects added with `tes3.addMagicEffect`.]],
	arguments = {
		{ name = "id", type = "integer", description = "Maps to values in [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) table." }
	},
	returns = { name = "magicEffect", type = "tes3magicEffect|nil" }
}