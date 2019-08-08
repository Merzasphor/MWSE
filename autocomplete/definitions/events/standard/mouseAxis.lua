return {
	description = "The mouseAxis event fires when the mouse is moved, providing deltaX and deltaY values.",
	eventData = {
		["deltaX"] = {
			type = "number",
			readonly = true,
			description = "The difference in horizontal mouse position from the previous frame.",
		},
		["deltaY"] = {
			type = "number",
			readonly = true,
			description = "The difference in vertical mouse position from the previous frame.",
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
}