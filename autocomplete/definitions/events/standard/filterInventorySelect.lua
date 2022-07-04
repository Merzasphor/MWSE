return {
	type = "event",
	description = "This event fires when an inventory filter has been selected for an item.",
	eventData = {
		["item"] = {
			type = "tes3item",
			readOnly = true,
			description = "The item being filtered.",
		},
		["itemData"] = {
			type = "tes3itemData",
			readOnly = true,
			description = "The item data for the item being filtered.",
		},
		["type"] = {
			type = "string",
			readOnly = true,
			description = "The inventory filter type.",
		},
		["filter"] = {
			type = "boolean",
			description = "Set this value to `true` to make the item appear in the inventory. If this is set to `false` the item won't appear in the inventory."
		}
	},
	filter = "type"
}