return {
	type = "event",
	description = "This event is triggered when a sound is played by the game or when `tes3.playSound()` is called.",
	related = { "addTempSound" },
	eventData = {
		["sound"] = {
			type = "tes3sound",
			description = "The sound going to be played.",
		},
		["reference"] = {
			type = "tes3reference",
			description = "The reference which is emiting the sound.",
		},
		["flags"] = {
			type = "number",
			readOnly = true,
			description = "A flag whether the sound is looping or not. 0 means the sound doesn't loop, 1 means the sound loops."
		},
		["volume"] = {
			type = "number",
			description = "The volume of the sound. In range [1, 250].",
		},
		["pitch"] = {
			type = "number",
			description = "The pitch-shift multiplier. For 22kHz audio (most typical) it can have the range [0.005, 4.5]; for 44kHz audio it can have the range [0.0025, 2.25].",
		},
		["isVoiceover"] = {
			type = "boolean",
			description = "A flag whether the sound is a voiced line, which are usually found in the Sound\\Vo data folder.",
		},
	},
	filter = "sound",
	blockable = true,
}
