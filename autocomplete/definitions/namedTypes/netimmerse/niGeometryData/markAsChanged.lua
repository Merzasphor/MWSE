return {
	type = "method",
	description = [[Indicates to the renderer that the geometry has changed since the object was last rendered. If this function is not called, the renderer may continue to use prepacked buffers which contain obsolete data. This function must be called after vertices, normals, colors, or texture coordinates are changed.]],
	arguments = {
		{ name = "flags", type = "number" },
	},
}