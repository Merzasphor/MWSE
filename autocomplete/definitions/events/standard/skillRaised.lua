return {
	type = "event",
	description = "This event is invoked whenever the player naturally gains a new level a skill. This is typically through exercise, training, or reading books.",
	eventData = {
		["skill"] = {
			type = "number",
			readOnly = true,
			description = "The skill that gained a new level experience.",
		},
		["level"] = {
			type = "number",
			readOnly = true,
			description = "The new level of the skill.",
		},
        ["source"] = {
            type = "",
            description = "The source of the skill raise. Its values are tes3.skillRaiseSource.* constants.",
        },
	},
	filter = "skill",
}
