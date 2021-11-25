return {
	type = "function",
	description = [[Returns the complex name of a magic effect, taking into account attribute or skill values.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "effect", type = "number", description = "The effect ID to get the name of." },
			{ name = "attribute", type = "number", optional = true, description = "The attribute ID to use, if applicable." },
			{ name = "skill", type = "number", optional = true, description = "The skill ID to use, if applicable." },
		},
	}},
	returns = {
		{ name = "complexName", type = "string" }
	},
}