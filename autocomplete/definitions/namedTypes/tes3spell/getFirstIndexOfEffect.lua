return {
	type = "method",
	description = [[Gets the first index of an effect ID in the spell effect table. Returns `-1` if provided effect doesn't exist in the spell]],
	arguments = {
		{ name = "effectId", type = "number", optional = false, description = "A value from [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) table." },
	},
	valuetype = "integer",
}
