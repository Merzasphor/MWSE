return {
	type = "function",
	description = [[Saves a serializable table to Data Files\MWSE\{fileName}.json, using json.encode.]],
	arguments = {
		{ name = "fileName", type = "string" },
		{ name = "object", type = "unknown" },
		{ name = "config", type = "table", optional = true },
	},
	valuetype = "table",
}