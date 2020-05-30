return {
	description = "This event fires immediately after a dialogue response is processed.",
	eventData = {
		["command"] = {
			type = "string",
			readonly = true,
			description = "The command.",
		},
		["reference"] = {
			type = "tes3reference",
			readonly = true,
			description = "The reference.",
		},
		["variables"] = {
			type = "tes3scriptVariables",
			readonly = true,
			description = "The script variables.",
		},
		["dialogue"] = {
			type = "tes3dialogue",
			readonly = true,
			description = "The dialogue object.",
		},
		["info"] = {
			type = "tes3dialogueInfo",
			readonly = true,
			description = "The dialogue info object.",
		},
	},
}