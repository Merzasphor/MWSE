return {
	type = "value",
	description = [[Loads a list of all shaders. This is not a constant-held collection, and each shader handle is initialized anew each time this function is called. Cache this value when you are sure that shaders are not added or removed.]],
	readOnly = true,
	valuetype = "mgeShaderHandle[]",
}
