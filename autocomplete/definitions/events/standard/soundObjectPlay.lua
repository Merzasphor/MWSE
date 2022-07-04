return {
	type = "event",
	description = "This event triggers before certain object sounds are about to be played. For example, item pickup sounds.",
	eventData = {
		["sound"] = {
			type = "tes3sound",
			description = "The sound about to be played.",
		},
		["flags"] = {
			type = "number",
			description = "A flag whether the sound is looping or not. 0 means the sound doesn't loop, 1 means the sound loops.",
		},
		["volume"] = {
			type = "number",
			description = "The volume of the sound. In range [1, 250].",
		},
		["pitch"] = {
			type = "number",
			description = "The pitch-shift multiplier. For 22kHz audio (most typical) it can have the range [0.005, 4.5]; for 44kHz audio it can have the range [0.0025, 2.25].",
		},
		["isNot3D"] = {
			type = "boolean",
			description = "",
		},
	},
	filter = "sound",
	blockable = true,
}
