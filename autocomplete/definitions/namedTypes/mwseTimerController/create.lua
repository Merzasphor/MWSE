return {
	type = "method",
	description = [[Creates a timer for the given Timer Controller.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "type", type = "number" },
			{ name = "duration", type = "number" },
			{ name = "callback", type = "function" },
			{ name = "iterations", type = "number", optional = true },
			{ name = "data", type = "table|nil" },
		}
	}},
	returns = "timer",
	valuetype = "mwseTimer",
}
