return {
	type = "function",
	description = [[Makes a HUD element fullscreen. If a HUD ID is provided, this is a warpper for MGEFullscreenHUD, otherwise it is a wrapper for MGENIDFullscreenHUD.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "hud", type = "string", optional = true }
		},
	}},
}