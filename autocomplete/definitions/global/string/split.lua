return {
	type = "function",
	description = "Returns an array-style table with `str` split by `sep`. The `sep`erator is not part of the results.",
	arguments = {
		{ name = "str", type = "string", description = "The string to split." },
		{ name = "sep", type = "string", description = "The token to split the string by." },
	},
	returns = {
		{ name = "split", type = "table" },
	},
}