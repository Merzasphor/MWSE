return {
	type = "function",
	description = [[Returns true if the table is empty, otherwise, it returns false.]],
	arguments = {
		{ name = "t", type = "table" },
		{ name = "deepCheck", type = "boolean", default = false, description = "If true, subtables will also be checked to see if they are empty." },
	},
	valuetype = "boolean",
}
