return {
	type = "function",
	description = [[Gets the index of a given journal, or nil if no valid journal could be found.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "tes3dialogue|string" },
		},
	}},
	returns = "index",
	valuetype = "number",
}