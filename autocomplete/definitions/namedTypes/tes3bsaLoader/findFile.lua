return {
	type = "method",
	description = [[Searches for a file in the archive list, and returns the archive and index that it can be found in.]],
	arguments = {
		{ name = "path", type = "string", description = "The path to the file held in the archive." },
	},
	returns = {
		{ name = "archive", type = "tes3archive|nil", description = "The found archive, or `nil` if no result was found." },
		{ name = "index", type = "number|nil", description = "The index in the archive that the path was found at, or `nil` if no result was found." },
	},
}
