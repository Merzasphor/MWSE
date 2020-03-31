return {
	description = "This event fires when a soul gem target is filtered",
	eventData = {
		["soulGem"] = {
			type = "tes3misc",
			readonly = true,
			description = "The soul gem object.",
		},
		["mobile"] = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor.",
		},
		["reference"] = {
			type = "tes3reference",
			readonly = true,
			description = "The reference.",
		},
	},
}