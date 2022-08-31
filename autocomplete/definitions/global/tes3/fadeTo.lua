return {
	type = "function",
	description = [[Similar to the vanilla FadeTo mwscript command.]],
	arguments = {{
		name = "params",
		type = "table",
		optional = true,
		tableParams = {
			{ name = "fader", type = "tes3fader", optional = true, description = "Defaults to the transition fader." },
			{ name = "duration", type = "number", optional = true, default = "1.0", description = "Time, in seconds, for the fade." },
			{ name = "value", type = "number", optional = true, default = "1.0" },
		},
	}},
}