return {
	type = "function",
	description = [[]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "text", type = "string", optional = true, default = "", description = "The text of the shown message." },
			{ name = "style", type = "number", optional = true, default = 0, description = "" },
			{ name = "answerIndex", type = "number", optional = true, default = 0, description = "" },
		},
	}},
}
