return {
	type = "event",
	description = "This event is triggered when a mobile object collides with water and all the frames during the collision.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileObject",
			readOnly = true,
			description = "Mobile object which collided.",
		},
		["reference"] = {
			type = "tes3mobileObject",
			readOnly = true,
			description = "`mobile`'s reference.",
		},
		["inWater"] = {
			type = "boolean",
			readOnly = true,
			description = "",
		},
	},
	filter = "reference",
}
