return {
	type = "event",
	description = "This event is raised when the potential activation target for the player changes.",
	eventData = {
		["current"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The activation target for the player, should they press the activation key. This can be nil when the player is not looking at an activateable object.",
		},
		["previous"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The previous activation target. If the player picked up or activated the previous target, this value may become nil, as the reference no longer exists after being taken.",
		},
	},
	filter = "current",
}