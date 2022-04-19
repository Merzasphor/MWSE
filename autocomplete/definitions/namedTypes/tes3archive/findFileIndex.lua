return {
	type = "method",
	description = [[Searches for a file in the archive, and returns the index that it can be found in.]],
	arguments = {
		{ name = "path", type = "string", description = "The path to the file held in the archive." },
	},
	returns = {
		{ name = "index", type = "number|nil", description = "The index in the archive that the path was found at, or `nil` if no result was found." },
	},
}
