return {
	description = "The mouseButtonDown event fires when a button on the mouse is pressed.",
	eventData = {
		["button"] = {
			type = "number",
			readonly = true,
			description = "The button index that was pressed.",
		},
		["isControlDown"] = {
			type = "number",
			readonly = true,
			description = "True if control is held.",
		},
		["isAltDown"] = {
			type = "number",
			readonly = true,
			description = "True if alt  is held.",
		},
		["isSuperDown"] = {
			type = "number",
			readonly = true,
			description = "True if super (Windows key) is held.",
		},
	},
	filter = "button",
}