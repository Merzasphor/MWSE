return {
	type = "function",
	description = [[Sets the effect for a HUD element. If a HUD ID is provided, this is a warpper for MGEChangeHUDEffect, otherwise it is a wrapper for MGENIDChangeHUDEffect.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "hud", type = "string", optional = true },
			{ name = "effect", type = "string" },
		},
	}},
}