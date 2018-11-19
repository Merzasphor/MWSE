return {
	type = "function",
	description = [[Frees a HUD element. If a HUD ID is provided, this is a warpper for MGEFreeHUD, otherwise it is a wrapper for MGENIDFreeHUD.]],
	arguments = {
		{ name = "hud", type = "string", optional = true }
	},
}