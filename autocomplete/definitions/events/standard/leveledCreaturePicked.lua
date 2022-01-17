return {
	type = "event",
	description = "This event is called after any leveled creature list is resolved. The event may be filtered by its list, and its pick can be overwritten. While this event allows for customization, the leveled list may be altered directly as well.",
	related = { "leveledCreaturePicked", "leveledItemPicked" },
	eventData = {
		["list"] = {
			type = "tes3leveledCreature",
			readOnly = true,
			description = "The list responsible for creating a pick.",
		},
		["pick"] = {
			type = "tes3creature|nil",
			--readOnly = true,
			description = "The result of the pick by vanilla mechanism. This can be modified to change the result to something else.",
		},
		["source"] = {
			type = "string",
			description = [[The context that the creature is being spawned in. Valid values include: `"reference"` for when spawned from a placed leveled spawn; `"emptyCell"` for when the player is exploring empty, undefined exterior cells; `"sleepInterrupt"` for when a random creature is chosen to attack the player when resting; and `"script"` for otherwise scripted picking.]],
		},
		["spawner"] = {
			type = "tes3reference|nil",
			description = "If spawned from a placed leveled creature reference, this is a handle to the creating reference.",
		},
		["cell"] = {
			type = "tes3cell|nil",
			description = "The cell associated with the pick, if any. This may be the `spawner`'s cell, the temporarily created empty cell, or the cell the player's sleep was interrupted in.",
		},
	},
	filter = "list",
	blockable = true,
}
