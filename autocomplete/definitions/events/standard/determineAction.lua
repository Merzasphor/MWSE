return {
	description = "This event fires when an actor determines an action in a combat session.",
	eventData = {
		["session"] = {
			type = "tes3combatSession",
			readonly = true,
			description = "The combat session the action is being determined for.",
		},
	},
}