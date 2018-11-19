return {
	type = "function",
	description = [[Determines if a file exists on the filesystem or inside of a bsa. The returned string will be "file" or "bsa".]],
	arguments = {
		{ name = "path", type = "string" }
	},
	returns = "exists",
	valuetype = "string",
}