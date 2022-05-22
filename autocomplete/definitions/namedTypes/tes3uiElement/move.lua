return {
	type = "method",
	description = [[Copies this element to a new parent, then destroys this element. This function can have unintended consequences. The specifics of what exact elements are being copied is important.]],
	arguments = {
		{ name = "to", type = "tes3uiElement", description = "Where to create the copy." },
	},
	returns = {
		{ name = "copy", type = "tes3uiElement", description = "The created copy." }
	}
}