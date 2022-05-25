return {
	type = "function",
	description = [[Gets a value in a table. If the key doesn't exist in the table, a specified default value will be returned instead.]],
	arguments = {
		{ name = "t", type = "table" },
		{ name = "key", type = "any", description = "The key to use to access the table." },
		{ name = "defaultValue", type = "any", description = "The default value if the key didn't exist in the table." },
	},
	valuetype = "any",
}