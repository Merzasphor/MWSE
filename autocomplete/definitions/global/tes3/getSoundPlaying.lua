return {
	type = "function",
	description = [[Determines if a sound is playing, optionally filtered to a given reference.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "sound", type = "tes3sound|string" },
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", optional = true },
		},
	}},
	returns = "soundIsPlaying",
	valuetype = "boolean",
}
