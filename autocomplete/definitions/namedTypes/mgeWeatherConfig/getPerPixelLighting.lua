return {
	type = "function",
	description = [[Gets the PPL data for a weather from MGE. These are returned in a table with the `sun` and `ambient` keys, as well as the `weather` redefined. The result table can be modified, then sent back to `setPerPixelLighting`.]],
	arguments = {
		{ name = "weather", type = "number" },
	},
	returns = {
		{ name = "result", type = "table<string, number>" },
	},
}
