return {
	type = "event",
	description = "This event is raised when determining the block chance for an actor. This does not affect ranged or magic attacks and ignores attacks outside of the normal blocking angles, like being attacked from behind. Blocking is disabled in some situations, like being paralyzed or attacking.",
	eventData = {
		["attacker"] = {
			type = "tes3reference",
			readOnly = true,
			description = "A shortcut to the attacker mobile's reference.",
		},
		["attackerMobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile that is attacking.",
		},
		["target"] = {
			type = "tes3reference",
			readOnly = true,
			description = "A shortcut to the target mobile's reference.",
		},
		["targetMobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile that is being attacked.",
		},
		["blockChance"] = {
			type = "number",
			description = "The block chance for the actor. This can be adjusted.",
		},
	},
	filter = "attacker.baseObject",
}