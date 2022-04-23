return {
	type = "event",
	description = "The potionBrewFailed event is raised when the player fails a potion brew attempt.",
	eventData = {
		["alembic"] = {
			type = "tes3apparatus",
			readOnly = true,
			description = "The alembic apparatus used to create the potion.",
		},
		["calcinator"] = {
			type = "tes3apparatus",
			readOnly = true,
			description = "The calcinator apparatus used to create the potion.",
		},
		["mortar"] = {
			type = "tes3apparatus",
			readOnly = true,
			description = "The mortar apparatus used to create the potion.",
		},
		["retort"] = {
			type = "tes3apparatus",
			readOnly = true,
			description = "The retort apparatus used to create the potion.",
		},
		["ingredients"] = {
			type = "tes3ingredient[]",
			readOnly = true,
			description = "Ingredients which were used to create the potion.",
		},
	},
}
