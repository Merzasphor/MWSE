return {
	type = "method",
	description = [[Creates a timer for the given Timer Controller.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "duration", type = "number" },
			{ name = "callback", type = "function|string" },
			{ name = "iterations", type = "integer", optional = true, default = 1 },
			{ name = "persists", type = "boolean", optional = true, default = true },
			{ name = "data", type = "table|nil", optional = true, default = "nil" },
		}
	}},
	returns = { name = "timer", type = "mwseTimer" }
}
