return {
	type = "event",
	description = "This event can be used to prevent the player from resting by returning false.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor that is preventing the player from resting.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "Mobile's associated reference.",
		},
	},
	filter = "mobile",
	blockable = true,
}
