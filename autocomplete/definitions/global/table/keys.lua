return {
	type = "function",
	description = [[Returns an array-style table of all keys in the given table, t.]],
	arguments = {
		{ name = "t", type = "table", description = "The table to get keys for." },
		{ name = "sortFunction", type = "function", optional = true, description = "The function used to sort table keys. If one is not provided, it uses the default table sorting function." },
	},
	returns = {
		{ name = "keys", type = "table", description = "A sorted array of all table keys." },
	},
}