return {
	type = "event",
	description = "This event is raised when an in-world `tes3reference` for an item is about to be converted to fit into a `tes3itemStack`. Note that reference.itemData.owner is always nil, as the game clears it earlier when evaluating theft mechanics.",
	eventData = {
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The reference about to be converted.",
		},
	},
}