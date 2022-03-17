return {
	type = "function",
	description = [[Sets the effect float variable for a HUD element. This is a wrapper for MGENIDSetHUDEffectFloat.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "hud", type = "string", optional = true },
			{ name = "variable", type = "string" },
			{ name = "value", type = "number" },
		},
	}},
}