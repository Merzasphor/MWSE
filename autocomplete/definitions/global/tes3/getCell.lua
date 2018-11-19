return {
	type = "function",
	description = [[Finds a cell, either by an id or an X/Y grid position.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "string", description = "The cell's ID. If not provided, x and y must be." },
			{ name = "x", type = "number" },
			{ name = "y", type = "number" },
		},
	}},
	returns = "cell",
	valuetype = "tes3cell",
}