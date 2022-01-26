return {
	type = "event",
	description = "This event is raised when a book's text is about to be displayed. By providing your own text, you can overwrite what is going to be displayed.",
	eventData = {
		["book"] = {
			type = "tes3book",
			readOnly = true,
			description = "The book whose text is being retrieved.",
		},
		["text"] = {
			type = "string",
			description = "If set, the book's text will be overwritten with this value. It needs to follow book text conventions as in the Construction Set. In essence, it uses HTML syntax. Important: every book needs to end with a `<BR>` statement to be displayed properly.",
		},
	},
	filter = "book",
	examples = {
		["changeText"] = {
			title = "Change the text of a book",
			description = "This will make every book read Sweetroll."
		},
	},
}