return {
	type = "event",
	description = "This event is triggered when a mesh is loaded.",
	eventData = {
		["path"] = {
			type = "string",
			description = "The path to the mesh, relative to Data Files\\Meshes",
		},
		["node"] = {
			type = "niAVObject",
			description = "The niAVObject-derived object of the loaded mesh.",
		},
	},
	filter = "path",
}
