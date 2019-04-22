return {
	description = "This event triggers when an actor dies.",
	eventData = {
		mobile = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor that has died.",
		},
		reference = {
			type = "tes3reference",
			readonly = true,
			description = "mobile’s associated reference.",
		},
	},
}