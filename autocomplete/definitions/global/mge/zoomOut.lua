return {
	type = "function",
	description = [[Wrapper for MGEZoomOut, or MGEZoomOutBy if an amount is provided.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "amount", type = "number", optional = true }
		},
	}},
}