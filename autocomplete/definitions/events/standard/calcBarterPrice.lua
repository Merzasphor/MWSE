return {
	description = "This event is raised when an item price is being determined when bartering.",
	eventData = {
		["item"] = {
			type = "tes3item",
			readonly = true,
			description = "The item, if any, that is being bartered.",
		},
		["itemData"] = {
			type = "tes3itemData",
			readonly = true,
			description = "The item data for the bartered item.",
		},
		["mobile"] = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor for who is selling or buying. May not always be available.",
		},
		["reference"] = {
			type = "tes3reference",
			readonly = true,
			description = "A shortcut to the mobile's reference. May not always be available.",
		},
		["basePrice"] = {
			type = "number",
			readonly = true,
			description = "The base price of the item, before any event modifications.",
		},
		["price"] = {
			type = "number",
			description = "The price of the item. This can be modified, but ensure that the buy/sell price is matched or there will be odd behavior.",
		},
		["count"] = {
			type = "number",
			readonly = true,
			description = "The number of items being bartered.",
		},
		["buying"] = {
			type = "boolean",
			readonly = true,
			description = "If true, the player is buying, otherwise the player is selling.",
		},
	},
}