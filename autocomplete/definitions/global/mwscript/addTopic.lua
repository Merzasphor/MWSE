return {
	type = "function",
	description = [[Wrapper for the AddItem mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "topic", type = "tes3dialogue|string" },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
