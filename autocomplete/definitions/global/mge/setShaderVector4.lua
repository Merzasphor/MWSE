return {
	type = "function",
	description = [[Sets a shader's vector variable. Wrapper for mwscript's MGEShaderSetVector.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "shader", type = "string" },
			{ name = "variable", type = "string" },
			{ name = "value", type = "table", description = "A table of 4 values." },
		},
	}},
}