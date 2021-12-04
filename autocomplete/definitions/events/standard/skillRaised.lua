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
            type = "tes3.skillRaiseSource",
            description = "The source of the skill raise. Its values are available as [`tes3.skillRaiseSource`](https://mwse.github.io/MWSE/references/skill-raise-sources/) enumeration.",
        },
	},
	filter = "skill",
}
