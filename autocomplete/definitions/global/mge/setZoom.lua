return {
	type = "function",
	description = [[Wrapper for MGEZoom, or MGESetZoom if set to animate.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "amount", type = "number" },
			{ name = "animate", type = "boolean", optional = true, default = false },
		},
	}},
}