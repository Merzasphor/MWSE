return {
	description = "The enterFrame event occurs at the start of every frame, including when the game is paused or in menu mode.",
	eventData = {
		delta = {
			type = "number",
			readonly = true,
			description = "The number of seconds since the last frame.",
		},
		menuMode = {
			type = "boolean",
			readonly = true,
			description = "If the game is paused- in the inventory or a menu, etc.",
		},
	},
}