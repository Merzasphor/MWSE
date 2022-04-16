return {
	type = "event",
	description = "calcSunDamageScalar is used when calculating the amount of damage to apply for the Sun Damage magic effect.",
	eventData = {
		["damage"] = {
			type = "number",
			readOnly =false,
			description = "The previously calculated sun damage.",
		},
	},
}
