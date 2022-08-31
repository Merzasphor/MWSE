return {
	type = "function",
	description = [[Saves the game.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "file", type = "string", optional = true, default = "\"quiksave\"", description = "The filename of the save that will be created, without extension." },
			{ name = "name", type = "string", optional = true, default = "\"Quicksave\"", description = "The display name of the save." },
		},
	}},
	returns = "saved",
	valuetype = "boolean",
}