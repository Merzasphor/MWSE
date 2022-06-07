return {
	type = "function",
	description = [[Gets the wind speed for a weather from MGE. This is returned in a table with the `speed` key, as well as the `weather` redefined. The result table can be modified, then sent back to `setWind`.]],
	arguments = {
		{ name = "weather", type = "number" },
	},
	returns = {
		{ name = "result", type = "table<string, number>", description = "A package containing the speed property." }
	},
}
