return {
	type = "function",
	description = [[Sets a shader's long variable. Wrapper for mwscript's MGEShaderSetLong.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "shader", type = "string" },
			{ name = "variable", type = "string" },
			{ name = "value", type = "number" },
		},
	}},
}