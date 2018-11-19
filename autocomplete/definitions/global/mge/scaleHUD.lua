return {
	type = "function",
	description = [[Scales a HUD element. If a HUD ID is provided, this is a warpper for MGEScaleHUD, otherwise it is a wrapper for MGENIDScaleHUD.]],
	arguments = {
		{ name = "hud", type = "string", optional = true },
		{ name = "x", type = "number" },
		{ name = "y", type = "number" },
	},
}