return {
	type = "event",
	description = "This event triggers when a power is recharged, and may be used again. In Morrowind, powers are a type of spells which may be cast once per day and don't cost any magicka.",
	eventData = {
		["power"] = {
			type = "tes3spell",
			readOnly = true,
			description = "A power which recharged.",
		},
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The actor whose power recharged.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "Mobile’s associated reference.",
		},
	},
	filter = "power",
}
