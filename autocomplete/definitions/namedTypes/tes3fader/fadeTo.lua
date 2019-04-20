return {
	type = "method",
	description = [[Transitions the fader to a value over a given duration.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "value", type = "number", default = 1, description = "The value to fade to." },
			{ name = "duration", type = "number", default = 1, description = "The time it takes to fade, in seconds." },
		}
	}},
}