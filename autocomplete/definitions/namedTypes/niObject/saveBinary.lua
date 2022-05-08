return {
	type = "method",
	description = [[Serializes the object, and writes it to the given file.]],
	arguments = {
		{ name = "path", type = "string", description = "The path to write the file at, relative to the Morrowind installation folder." },
	},
	returns = {
		{ name = "success", type = "boolean", description = "If true the object was successfully serialized." },
	},
}
