return {
	type = "function",
	description = [[Plays a sound on a given reference. Provides control over volume (including volume channel), pitch, and loop control.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "sound", type = "tes3sound|string" },
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The reference to attach the sound to.", optional = true },
			{ name = "loop", type = "boolean", default = false },
			{ name = "mixChannel", type = "number", default = "tes3.audioMixType.effects", description = "The channel to base volume off of. Maps to tes3.audioMixType constants." },
			{ name = "volume", type = "number", default = "1.0", description = "A value between 0.0 and 1.0 to scale the volume off of." },
			{ name = "pitch", type = "number" },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
