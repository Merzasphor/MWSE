return {
	type = "event",
	description = "The potionBrewed event is raised when the player brews a new potion.",
	eventData = {
		["object"] = {
			type = "tes3alchemy",
			readOnly = true,
			description = "The potion created by the player.",
		},
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
	examples = {
		["replace"] = {
			title = "Replace a brewed potion with a modified version",
		},
	},
}
