return {
	type = "function",
	description = [[Enables a HUD element. If a HUD ID is provided, this is a warpper for MGEEnableHUD, otherwise it is a wrapper for MGENIDEnableHUD.]],
	arguments = {
		{ name = "hud", type = "string", optional = true }
	},
}