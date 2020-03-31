return {
	description = "This event fires when a dialogue info object is filtered.",
	eventData = {
		["info"] = {
			type = "tes3dialogueInfo",
			readonly = true,
			description = "The dialogue info object.",
		},
		["actor"] = {
			type = "tes3object",
			readonly = true,
			description = "The actor.",
		},
		["reference"] = {
			type = "tes3reference",
			readonly = true,
			description = "The reference.",
		},
		["source"] = {
			type = "number",
			readonly = true,
			description = "The source.",
		},
		["dialogue"] = {
			type = "tes3dialogue",
			readonly = true,
			description = "The dialogue object.",
		},
		["passes"] = {
			type = "bool",
			readonly = true,
			description = "Indicates if the filter passes.",
		},
	},
}