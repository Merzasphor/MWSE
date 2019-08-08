return {
	description = "The menuEnter event fires when the player enters menu mode.",
	eventData = {
		["menu"] = {
			type = "tes3uiElement",
			readonly = true,
			description = "The new top-level menu.",
		},
		["menuMode"] = {
			type = "boolean",
			readonly = true,
			description = "Always true for this event. This parameter is only useful when registering the same callback for menuEnter and menuExit events.",
		},
	},
	filter = "menu.name",
}