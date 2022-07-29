return {
	type = "function",
	description = [[Loads a mesh file and provides a scene graph object.]],
	arguments = {
		{ name = "path", type = "string", description = "Path, relative to Data Files/Meshes." },
		{ name = "useCache", type = "boolean", optional = true, default = true, description = "If false, a new object will be created even if it had been previously loaded." },
	},
	returns = "model",
	valuetype = "niNode",
}