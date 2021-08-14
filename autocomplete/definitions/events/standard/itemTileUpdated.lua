return {
	type = "event",
	description = "This event fires when a dialogue response is triggered.",
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