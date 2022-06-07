return {
	type = "function",
	description = [[Sets the wind speed for a weather in MGE. The result table of `getWind` can be modified then passed to this function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "weather", type = "number" },
			{ name = "speed", type = "number" },
		},
	}},
}
