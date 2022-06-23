return {
	type = "event",
	description = [[This event is invoked whenever an actor makes an attack with their fists or a weapon, or a creature makes any attack. It occurs at the moment a melee attack would hit, at the end of a melee weapon strike. For projectile attacks, it is when an arrow is about to detach from its bow. A target is not required to be present for this event.

Lockpicks and probes do not invoke this event.]],
	related = { "attack", "attackStart" },
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor making the attack.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "A shortcut to the reference that is attacking.",
		},
		["targetMobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor being attacked. May be nil, e.g. if nothing was targeted.",
		},
		["targetReference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "A shortcut to the reference being attacked. May be nil, e.g. if nothing was targeted.",
		},
	},
	filter = "reference",
	examples = {
		["ForceMiss"] = {
			title = "Convert Hits to Misses",
		},
	},
}