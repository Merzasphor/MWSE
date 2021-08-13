return {
	type = "function",
	description = "Returns an array-style table with `str` split by `sep`. The `sep`erator is not part of the results. By default the `sep`erator is `%s`, splitting the given `str`ing by spaces.",
	arguments = {
		{ name = "str", type = "string", description = "The string to split." },
		{ name = "sep", type = "string", default = [["%s"]], description = "The token to split the string by." },
	},
	returns = {
		{ name = "split", type = "table" },
	},
}