return {
	type = "method",
	description = [[Returns the index of a first effect of a given effectId in the parent `tes3enchantment` object.]],
	arguments = {
		{ name = "effectId", type = "number", description = [[The effectId to perform a check for. Maps to [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) constants, including magic effects added with [`tes3.addMagicEffect()`](https://mwse.github.io/MWSE/apis/tes3/#tes3addmagiceffect).]] },
	},
	returns = "index",
	valuetype = "number",
}
