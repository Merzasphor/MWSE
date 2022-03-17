return {
	type = "function",
	description = [[Sets the effect vector variable for a HUD element. This is a wrapper for MGENIDSetHUDEffectVec.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "hud", type = "string", optional = true },
			{ name = "variable", type = "string" },
			{ name = "value", type = "table", description = "A table of 4 values." },
		},
	}},
}