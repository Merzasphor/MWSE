return {
	type = "function",
	description = [[Positions a HUD element. If a HUD ID is provided, this is a warpper for MGEPositionHUD, otherwise it is a wrapper for MGENIDPositionHUD.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "hud", type = "string", optional = true },
			{ name = "x", type = "number" },
			{ name = "y", type = "number" },
		},
	}},
}