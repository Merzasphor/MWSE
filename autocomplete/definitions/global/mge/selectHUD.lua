return {
	type = "function",
	description = [[Selects a HUD element, to assume for future HUD calls.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "hud", type = "string", optional = true },
		},
	}},
}