return {
	type = "method",
	description = [[Gets an arbitrary lua value from the UI element. Each element has the capability to store keyed lua data, as if it were a table, using this function and `setLuaData`.]],
	arguments = {
		{ name = "key", type = "string", description = "The key for the lua data." },
	},
	valuetype = "any",
}
