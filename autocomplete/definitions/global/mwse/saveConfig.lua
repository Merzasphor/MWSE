return {
	type = "function",
	description = [[Saves a config table to Data Files\\MWSE\\config\\{fileName}.json.]],
	arguments = {
		{ name = "fileName", type = "string" },
		{ name = "object", type = "unknown" },
		{ name = "config", type = "table", optional = true },
	},
	returns = "table",
}