return {
	type = "function",
	description = [[Disables a shader. Wrapper for mwscript's MGEDisableShader.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "shader", type = "string" }
		},
	}},
}