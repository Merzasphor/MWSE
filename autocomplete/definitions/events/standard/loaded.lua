return {
	description = "The loaded event fires after the game has been successfully loaded. This event is preceded by the load event.",
	eventData = {
		["filename"] = {
			type = "string",
			readonly = true,
			description = "The filename of the save that was loaded, not including file extension.",
		},
		["quickload"] = {
			type = "boolean",
			readonly = true,
			description = "If true, the load came from the quickload system.",
		},
		["newGame"] = {
			type = "boolean",
			readonly = true,
			description = "If true, a new game was started.",
		},
	},
}