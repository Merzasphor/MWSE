return {
	type = "function",
	description = [[Enables a shader. Wrapper for mwscript's MGEEnableShader.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "shader", type = "string" }
		},
	}},
}