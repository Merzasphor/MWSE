return {
	type = "function",
	description = [[Gets a value in a table. If the key doesn't exist in the table, a specified default value will be set in the table and returned instead.]],
	arguments = {
		{ name = "t", type = "table" },
		{ name = "key", type = "any", description = "The key to use to access the table." },
		{ name = "defaultValue", type = "any", description = "The default value to set and return if the key didn't exist in the table." },
	},
	valuetype = "any",
}