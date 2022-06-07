return {
	type = "function",
	description = [[Sets the PPL values for a weather in MGE. The result table of `getPerPixelLighting` can be modified then passed to this function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "weather", type = "number" },
			{ name = "sun", type = "number" },
			{ name = "ambient", type = "number" },
		},
	}},
}
