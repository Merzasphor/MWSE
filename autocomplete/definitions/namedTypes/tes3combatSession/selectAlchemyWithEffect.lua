return {
	type = "method",
	description = "Selects the alchemy item with the greatest value, for a given effect ID and loads it into the `selectedItem` property.",
	arguments = {
		{ name = "id", type = "integer" },
	},
	returns = {
		{ name = "result", type = "number" },
	}
}