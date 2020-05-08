return {
	type = "method",
	description = [[Applies a coloring effect to the fader.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "color", type = "tes3vector3|table", description = "The RGB values to set." },
			{ name = "flag", type = "boolean" },
		}
	}},
	valuetype = "boolean",
}