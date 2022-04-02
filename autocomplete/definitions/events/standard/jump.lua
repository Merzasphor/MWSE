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
	blockable = true,
	examples = {
		["doubleJumpHeight"] = {
			title = "Double jump height",
			description = "Double the height of every jump.",
		},
		["forcePlayerJumpHeight"] = {
			title = "Force player jump height",
			description = "Forces the jump height of the player to a fixed value, not taking into account attributes, skills, fatigue, encumbrance and other factors.",
		},
		["disableJumpingWhileEncumbered"] = {
			title = "Disable jumping while encumbered",
			description = "Disables jumping for the player if their current encumbrance is over 50%.",
		}
	}
}