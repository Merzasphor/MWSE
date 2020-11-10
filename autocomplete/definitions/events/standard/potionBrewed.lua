return {
	description = "The potionBrewed event is raised when the player brews a new potion.",
	eventData = {
		["object"] = {
			type = "tes3alchemy",
			readonly = true,
			description = "The potion created by the player.",
		},
		["alembic"] = {
			type = "tes3apparatus",
			readonly = true,
			description = "The alembic apparatus used to create the potion.",
		},
		["calcinator"] = {
			type = "tes3apparatus",
			readonly = true,
			description = "The calcinator apparatus used to create the potion.",
		},
		["mortar"] = {
			type = "tes3apparatus",
			readonly = true,
			description = "The mortar apparatus used to create the potion.",
		},
		["retort"] = {
			type = "tes3apparatus",
			readonly = true,
			description = "The retort apparatus used to create the potion.",
		},
		["ingredients"] = {
			type = "table",
			readonly = true,
			description = "An array of up to 4 tes3ingredient objects, which were used to create the potion.",
		},
	},
}