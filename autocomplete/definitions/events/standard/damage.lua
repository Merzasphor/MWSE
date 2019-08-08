return {
	description = "The damage event triggers before an actor is damaged. The damage value can be modified, or the damage can be prevented completely by blocking the event.",
	eventData = {
		damage = {
			type = "number",
			description = "The amount of damage done.",
		},
		mobile = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor that is taking damage.",
		},
		reference = {
			type = "tes3reference",
			readonly = true,
			description = "mobile’s associated reference.",
		},
	},
}