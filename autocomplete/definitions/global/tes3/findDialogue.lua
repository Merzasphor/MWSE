return {
	type = "function",
	description = [[Locates a root dialogue that can then be filtered down for a specific actor to return a specific dialogue info For example, a type of 2 and a page of 1 will return the "Greeting 0" topic.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "type", type = "number", description = "The type of dialogue to look for: 1 for voice, 2 for greeting, 3 for service." },
			{ name = "page", type = "number", description = "The page of dialogue to fetch." },
		},
	}},
	returns = {{ name = "dialogue", type = "tes3dialogue" }},
}
