return {
	type = "function",
	description = [[Determines if a file exists on the filesystem or inside of a bsa. The returned string will be "file" or "bsa".]],
	arguments = {
		{ name = "path", type = "string" }
	},
	returns = {
		{ name = "exists", type = "string?", description = "A string representing the file source. This can be either `file` or `bsa`." },
		{ name = "path", type = "string?", description = "If the file exists, this is a path to the file. If the file is from a BSA, it is a path inside the BSA." },
	},
}
