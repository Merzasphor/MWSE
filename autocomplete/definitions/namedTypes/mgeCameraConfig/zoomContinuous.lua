return {
	type = "function",
	description = [[Sets up continuous camera zoom. The zoom speed starts at `rate`. The speed will approach `targetRate` over time, if provided.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "rate", type = "number", optional = true },
			{ name = "targetRate", type = "number", optional = true },
		},
	}},
}
