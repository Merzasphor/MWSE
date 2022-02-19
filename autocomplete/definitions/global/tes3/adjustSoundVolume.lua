return {
	type = "function",
	description = [[Changes the volume of a sound that is playing on a given reference.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "sound", type = "tes3sound|string", description = "The sound object, or id of the sound to look for." },
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The reference to attach the sound to." },
			{ name = "mixChannel", type = "number", default = "tes3.soundMix.effects", description = "The channel to base volume off of. Maps to [`tes3.soundMix`](https://mwse.github.io/MWSE/references/sound-mix-types/) constants." },
			{ name = "volume", type = "number", default = "1.0", description = "A value between 0.0 and 1.0 to scale the volume off of." },
		},
	}},
}
