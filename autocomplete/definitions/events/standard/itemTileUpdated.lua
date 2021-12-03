return {
	type = "event",
	description = "This event is fired whenever an inventory item tile is updated, as well as when the tile is created. This can be used to easily manipulate or extend the appearance of inventory tiles.",
	eventData = {
		["element"] = {
			type = "tes3uiElement",
			readOnly = true,
			description = "The command.",
		},
		["item"] = {
			type = "tes3item",
			readOnly = true,
			description = "The reference.",
		},
		["itemData"] = {
			type = "tesitemData",
			readOnly = true,
			description = "The script variables.",
		},
		["menu"] = {
			type = "tes3uiElement",
			readOnly = true,
			description = "The dialogue object.",
		},
		["tile"] = {
			type = "tes3inventoryTile",
			readOnly = true,
			description = "The dialogue info object.",
		},
	},
}