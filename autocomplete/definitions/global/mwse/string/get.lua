return {
	type = "function",
	description = [[Returns the numerical key for a given string in storage, or nil if the string isn't in storage.]],
	arguments = {
		{ type = "string" }
	},
	returns = {
		{ type = "number", optional = true }
	},
}