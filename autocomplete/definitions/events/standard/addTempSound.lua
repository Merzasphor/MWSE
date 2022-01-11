return {
	type = "event",
	description = "",
	related = { "addSound" },
	eventData = {
		["path"] = {
			type = "string",
			description = "The path to the sound to play, relative to Data Files\\Sounds",
		},
		["reference"] = {
			type = "tes3reference",
			description = "The reference which is emiting the sound.",
		},
		["flags"] = {
			type = "number",
			readOnly = true,
			description = "A flag whether the sound is looping or not. 0 means the sound doesn't loop, 1 means the sound loops.",
		},
		["volume"] = {
			type = "number",
			description = "The volume of the sound. Volume = 1 means 100 % loudness. Values lower than 1 make the sound quiter."
		},
		["pitch"] = {
			type = "number",
			description = "Pitch of the sound.",
		},
		["isVoiceover"] = {
			type = "boolean",
			description = "A flag whether the sound is a voiced line, which are usually found in the Sound\\Vo data folder.",
		},
		["sound"] = {
			type = "tes3sound",
			description = "",
		},
	},
	filter = "sound",
	blockable = true,
}
