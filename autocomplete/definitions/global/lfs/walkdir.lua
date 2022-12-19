return {
	type = "function",
	description = [[An iterator that visits all files in a directory tree.]],
	arguments = {
		{ name = "path", type = "string", description = "The root path of the directory tree." },
	},
	valuetype = "iterator",
	examples = {
		["usage"] = {
			title = "Logging all the files present in Data files\\meshes\\ folder"
		}
	}
}
