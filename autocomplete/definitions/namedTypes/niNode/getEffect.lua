return {
	type = "method",
	description = [[Gets the effect of the given type.]],
	arguments = {
		{ name = "type", type = "integer", description = "Use the values from [`ni.dynamicEffectType`](https://mwse.github.io/MWSE/references/ni/dynamic-effect-types/) table." },
	},
	returns = { name = "effect", type = "niDynamicEffect|nil" },
}