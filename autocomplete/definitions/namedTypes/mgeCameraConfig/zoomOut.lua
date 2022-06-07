return {
	type = "function",
	description = [[Zooms out by the specified amount, or by a small amount if no amount is provided.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "amount", type = "number", amount = 0.0625 },
		},
	}},
}
