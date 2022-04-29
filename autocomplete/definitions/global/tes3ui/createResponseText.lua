return {
	type = "function",
	description = [[Creates a respond text. This function is used for the mwscript `Choice` function.]],
	arguments = { {
		name = "params",
		type = "table",
		tableParams = {
			{ name = "text", type = "string", description = "The text to display." },
			{ name = "type", type = "number", optional = true, description = "The type for the response. Defaults to `choice` responses." },
			{ name = "index", type = "number", optional = true, description = "The answer index for the response. Only used for `choice` responses." },
		},
	} },
}
