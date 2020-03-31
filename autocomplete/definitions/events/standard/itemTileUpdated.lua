return {
	description = "This event fires when a dialogue response is triggered.",
	eventData = {
		["element"] = {
			type = "tesuiElement",
			readonly = true,
			description = "The command.",
		},
		["item"] = {
			type = "tes3item",
			readonly = true,
			description = "The reference.",
		},
		["itemData"] = {
			type = "tesitemData",
			readonly = true,
			description = "The script variables.",
		},
		["menu"] = {
			type = "tesuiElement",
			readonly = true,
			description = "The dialogue object.",
		},
		["tile"] = {
			type = "tes3uiInventoryTile",
			readonly = true,
			description = "The dialogue info object.",
		},
	},
}