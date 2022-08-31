return {
	type = "function",
	description = [[Creates a string in storage, and returns the numerical key for it.

If the string is already in storage, the previous key will be returned.]],
	arguments = {
		{ name = "value", type = "string" }
	},
	returns = "number",
}