return {
	type = "function",
	description = [[Finds a loaded shader and returns a handle to it.]],
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
