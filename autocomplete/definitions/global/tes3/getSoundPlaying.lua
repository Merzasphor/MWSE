return {
	type = "function",
	description = [[Without a reference, this function returns true if the sound is playing unattached or on any reference. With a reference, it returns true if the sound is playing on that specific reference.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "sound", type = "tes3sound|string", description = "The sound object, or the ID of the sound to look for." },
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", optional = true },
		},
	}},
	returns = "soundIsPlaying",
	valuetype = "boolean",
}
