return {
	description = "The mouseWheel event fires when the mouse wheel is used, providing a delta value.",
	eventData = {
		["delta"] = {
			type = "number",
			readonly = true,
			description = "The direction and strength of the mouse wheel movement. This value is hardware dependent.",
		},
		["isControlDown"] = {
			type = "number",
			readonly = true,
			description = "True if control is held.",
		},
		["isAltDown"] = {
			type = "number",
			readonly = true,
			description = "True if alt is held.",
		},
		["isSuperDown"] = {
			type = "number",
			readonly = true,
			description = "True if super (Windows key) is held.",
		},
	},
}