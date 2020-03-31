return {
	description = "This event fires when an item in the contents menu is filtered.",
	eventData = {
		["tile"] = {
			type = "tes3uiInventoryTile",
			readonly = true,
			description = "The inventory tile being filtered.",
		},
		["item"] = {
			type = "tes3item",
			readonly = true,
			description = "The item being filtered.",
		},
		["itemData"] = {
			type = "tes3itemData",
			readonly = true,
			description = "The item data for the item being filtered.",
		},
	},
}