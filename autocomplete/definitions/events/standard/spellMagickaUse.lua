return {
	type = "event",
	description = "This event is triggered just before a spell or power is used by any actor. It allows modification of the magicka required to cast the spell. Magicka cost change is not reflected in the UI system, because the UI does not expect spell costs to change.",
	eventData = {
		["caster"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The caster of the spell.",
		},
		["spell"] = {
			type = "tes3spell",
			readOnly = true,
			description = "The spell being cast.",
		},
		["cost"] = {
			type = "number",
			description = "The magicka cost required to cast the spell. May be modified. This value is rounded to an integer when used by the engine.",
		},
		["instance"] = {
			type = "tes3magicSourceInstance",
			description = "The magic source instance.",
		},
	},
	filter = "caster",
}