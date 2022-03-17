return {
	type = "function",
	description = [[Cancels selection for a HUD element. Wrapper for mwscript's MGECancelWithHUD.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "hud", type = "string" },
		},
	}},
}