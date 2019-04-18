return {
	description = "This event is raised when a book's text is about to be displayed. By providing your own text, you can overwrite what is going to be displayed.",
	eventData = {
		button = {
			type = "number",
			readonly = true,
			description = "The button index, 0-based, that was pressed.",
		},
	},
}