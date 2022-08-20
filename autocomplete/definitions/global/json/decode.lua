return {
	type = "function",
	description = [[Decode string into a table.]],
	link = "http://dkolf.de/src/dkjson-lua.fsl/wiki?name=Documentation",
	arguments = {
		{ name = "s", type = "string" },
		{ name = "position", type = "number", optional = true, default = 1 },
		{ name = "nullValue", type = "string|nil", optional = true, default = "nil" },
	},
	valuetype = "table",
}