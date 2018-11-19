return {
	type = "function",
	description = [[Disables a HUD element. If a HUD ID is provided, this is a warpper for MGEDisableHUD, otherwise it is a wrapper for MGENIDDisableHUD.]],
	arguments = {
		{ name = "hud", type = "string", optional = true }
	},
}