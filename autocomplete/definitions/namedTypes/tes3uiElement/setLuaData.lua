return {
	type = "method",
	description = [[Sets an arbitrary lua value for the UI element. Each element has the capability to store keyed lua data, as if it were a table, using this function and `getLuaData`.]],
	arguments = {
		{ name = "key", type = "string", description = "The key for the lua data." },
		{ name = "value", type = "any", description = "The value to set." },
	},
}
