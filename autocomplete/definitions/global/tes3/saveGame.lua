return {
	type = "function",
	description = [[Saves the game.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "file", type = "string", default = "quiksave", description = "The filename of the save that will be created, without extension." },
			{ name = "name", type = "string", default = "Quicksave", description = "The display name of the save." },
		},
	}},
	returns = "saved",
	valuetype = "boolean",
}