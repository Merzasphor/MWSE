return {
	type = "event",
	description = "This event is called when determining the spell point cost of making a spell. The spell point cost can be modified.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor of the spellmaking service npc the player is interacting with.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "Mobile's related reference.",
		},
		["spellPointCost"] = {
			type = "number",
			description = "The spell point cost of the spell.",
		},
	},
}