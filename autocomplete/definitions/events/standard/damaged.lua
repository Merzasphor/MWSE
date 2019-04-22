return {
	description = "The damaged event triggers after an actor has been damaged.",
	eventData = {
		damage = {
			type = "number",
			readonly = true,
			description = "The amount of damage done.",
		},
		mobile = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor that took damage.",
		},
		reference = {
			type = "tes3reference",
			readonly = true,
			description = "mobile’s associated reference.",
		},
	},
}