return {
	type = "function",
	description = [[Sets the value of a global value. If the global could not be found, the function returns false.]],
	arguments = {
		{ name = "id", type = "string" },
		{ name = "value", type = "number" },
	},
	returns = "value",
	valuetype = "boolean",
}