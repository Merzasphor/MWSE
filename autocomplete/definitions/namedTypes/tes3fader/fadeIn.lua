return {
	type = "method",
	description = [[Transitions the fader to a value of `1` over a given duration.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "duration", type = "number", default = 1, description = "The time it takes to fade, in seconds." },
		}
	}},
}