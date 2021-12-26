return {
	type = "event",
	description = "This event is fired whenever an inventory item tile is updated, as well as when the tile is created. This can be used to easily manipulate or extend the appearance of inventory tiles.",
	eventData = {
		["element"] = {
			type = "tes3uiElement",
			readOnly = true,
			description = "The UI element that the tile is displayed on.",
		},
		["item"] = {
			type = "tes3item",
			readOnly = true,
			description = "The tile's item.",
		},
		["itemData"] = {
			type = "tes3itemData",
			readOnly = true,
			description = "The tile's item data, if any.",
		},
		["menu"] = {
			type = "tes3uiElement",
			readOnly = true,
			description = "The root menu of the tile. This will typically be the MenuInventory, MenuContents, or MenuBarter menus.",
		},
		["tile"] = {
			type = "tes3inventoryTile",
			readOnly = true,
			description = "The tile data itself. This typically contains references to all the other event fields, among other tile-specific information.",
		},
	},
}