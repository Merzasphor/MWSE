return {
	type = "method",
	description = [[Final volume of a provided type of audio, after master volume and its own volume adjustments. Music volume is an exception since it isn't affected by master volume.]],
	arguments = {
		{ name = "mix", type = "tes3.soundMix.* constants", description = "The type of sound mix to perform a check for." },
	},
	returns = {
		{ name = "volume", type = "number" },
	}
}
