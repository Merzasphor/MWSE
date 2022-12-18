return {
	type = "function",
	description = [[Creates a respond text. This function is used for the mwscript `Choice` function.]],
	arguments = { {
		name = "params",
		type = "table",
		tableParams = {
			{ name = "text", type = "string", description = "The text to display." },
			{ name = "type", type = "integer", optional = true, default = 2, description = "The type for the response. Defaults to `choice` responses. If set to `1`, a title will be made. Value of `0` corresponds to the main text, and value of `2` corresponds to red clickable choice text." },
			{ name = "index", type = "integer", optional = true, description = "The answer index for the response. Only used for `choice` responses." },
		},
	} },
}
