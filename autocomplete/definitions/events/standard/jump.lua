return {
	type = "event",
	description = "This event is called when an actor tries to jump. The `velocity` and `applyFatigueCost` can be modified.",
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
		["applyFatigueCost"] = {
			type = "boolean",
			description = "If `false`, this jump will not reduce fatigue.",
		},
		["isDefaultJump"] = {
			type = "boolean",
			readOnly = true,
			description = "If `true`, the jump has been initiated from the ground and without custom velocity or fatigue cost. This does not change if other event callbacks change any of these parameters.",
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