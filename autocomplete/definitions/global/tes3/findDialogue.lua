return {
	type = "function",
	description = [[Drops one or more items from a reference's inventory onto the ground at their feet.]],
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
