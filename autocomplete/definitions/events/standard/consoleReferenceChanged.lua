return {
	type = "event",
	description = [[This event is invoked when the player selects a new reference with the console, or unselects a reference.]],
	eventData = {
		["reference"] = {
			type = "tes3reference|nil",
			readOnly = true,
			description = "The newly selected reference, or nil if nothing is now selected.",
		},
	},
	filter = "reference",
}