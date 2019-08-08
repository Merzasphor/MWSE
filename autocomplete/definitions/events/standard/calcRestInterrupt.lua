return {
	description = "This event is called when the player is about to start resting. The hour and count of creatures can be modified, or disabled.",
	eventData = {
		hour = {
			type = "number",
			description = "The hour of rest remaining that the rest will be interrupted on.",
		},
		count = {
			type = "number",
			description = "The number of creatures interrupting rest. Set to 0 to prevent a spawn.",
		},
		resting = {
			type = "boolean",
			description = "If true, the player is attempting to rest, as opposed to wait.",
		},
		waiting = {
			type = "boolean",
			description = "If true, the player is attempting to wait, as opposed to rest.",
		},
	},
}