return {
	type = "function",
	description = [[Sets the texture for a given HUD element. If a HUD ID is provided, this is a warpper for MGEChangeHUDTexture, otherwise it is a wrapper for MGENIDChangeHUDTexture.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "hud", type = "string" },
			{ name = "texture", type = "string" },
		},
	}},
}