return {
	type = "function",
	description = [[Stops a sound playing. Without a reference, it will match unattached sounds. With a reference, it will only match a sound playing on that specific reference.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "sound", type = "tes3sound|string", description = "The sound object, or id of the sound to look for." },
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", optional = true, description = "The reference the sound is attached to." },
		},
	}},
}
