return {
	description = "This event is triggered just before an on-strike or on-use enchantment is used by any actor, and also by the UI system to label enchant charges. It allows modification of the charge required to use an enchantment.",
	eventData = {
		["caster"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The caster of the enchantment.",
		},
		["source"] = {
			type = "tes3enchantment",
			readOnly = true,
			description = "The enchantment being used or examined by the UI.",
		},
		["charge"] = {
			type = "number",
			description = "The charge required to cast the enchantment. May be modified.",
		},
	},
	filter = "caster",
}