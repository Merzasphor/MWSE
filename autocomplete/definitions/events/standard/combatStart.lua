return {
	description = "The combatStart event occurs when combat is about to begin between two actors. This event allows scripts to prevent combat from starting.",
	eventData = {
		["actor"] = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor who is entering combat.",
		},
		["target"] = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor who combat is being triggered against.",
		},
	},
}