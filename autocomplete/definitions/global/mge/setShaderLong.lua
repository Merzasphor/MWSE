return {
	type = "function",
	deprecated = true,
	description = "Sets a shader long value. Use the named variable interface on the shader handle instead.",
	arguments = { {
		name = "params",
		type = "table",
		tableParams = {
			{ name = "name", type = "string" },
			{ name = "variable", type = "string" },
			{ name = "value", type = "number" },
		},
	} },
}
