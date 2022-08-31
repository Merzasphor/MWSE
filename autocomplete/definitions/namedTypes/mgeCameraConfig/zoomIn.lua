return {
	type = "function",
	description = [[Zooms in by the specified amount, or by a small amount if no amount is provided.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "amount", type = "number", optional = true, default = 0.0625, },
		},
	}},
}
