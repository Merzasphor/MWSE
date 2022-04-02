return {
	type = "event",
	description = "This event is called when an actor tries to jump. The velocity can be modified.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor that is trying to jump.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "Mobile's related reference.",
		},
		["velocity"] = {
			type = "tes3vector3",
			description = "The velocity of the jump.",
		},
	},
	filter = "reference",
	blockable = true
}