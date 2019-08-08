return {
	description = "This event is raised when determining the hit chance for an actor.",
	eventData = {
		attackerMobile = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile who is making the attack.",
		},
		attacker = {
			type = "tes3reference",
			readonly = true,
			description = "A shortcut to the mobile's reference.",
		},
		targetMobile = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile who is being attacked. May not always be available.",
		},
		target = {
			type = "tes3reference",
			readonly = true,
			description = "A shortcut to the target mobile's reference. May not always be available.",
		},
		price = {
			type = "number",
			description = "The hit chance for the actor. This may be adjusted.",
		},
	},
	filter = "attacker",
}