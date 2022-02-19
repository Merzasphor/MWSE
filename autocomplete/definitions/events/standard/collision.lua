return {
	type = "event",
	description = "This event is triggered on a collision and all the frames during the collision.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileObject",
			readOnly = true,
			description = "Mobile object which collided with its target reference.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "Mobile object's associated reference.",
		},
		["target"] = {
			type = "tes3reference",
			readOnly = true,
			description = "Reference which mobile object has collided with.",
		},
	},
	filter = "reference",
	examples = {
		["playerBumpedIntoDoor"] = {
			title = "Shows a message when the player bumps into the door."
		}
	}
}
