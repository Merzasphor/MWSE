return {
	description = "This event is called after any leveled creature list is resolved. The event may be filtered by its list, and its pick can be overwritten. While this event allows for customization, the leveled list may be altered directly as well.",
	eventData = {
		["list"] = {
			type = "tes3leveledCreature",
			readonly = true,
			description = "The list responsible for creating a pick.",
		},
		["pick"] = {
            		type = "tes3creature",
			--readonly = true,
			description = "The result of the pick by vanilla mechanism. This can be modified to change the result to something else.",
		},
	},
	filter = "list",
}
