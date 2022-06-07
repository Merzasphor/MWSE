return {
	type = "function",
	description = [[Loads a shader by name, from the `Data Files/shaders/XEshaders` directory. Adds the shader to the existing shader list, or returns the existing shader if it is already loaded.

If the shader has a category annotation, it is inserted into a position that preserves the category ordering. Shaders without a category will be added to the end of the list.

Summary of category sort order:
* scene: Additional objects rendered into the scene.
* atmosphere: Atmosphere effects that render over all objects, such as mist.
* lens: Lens effects such as depth of field.
* sensor: Sensor effects such as bloom.
* tone: Tone mapping and color grading.
* final: Any effects that need to run last.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "name", type = "string" },
		},
	}},
	returns = {
		{ name = "shader", type = "mgeShaderHandle|nil" },
	},
}
