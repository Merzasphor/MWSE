return {
	type = "method",
	description = [[Copies this element to a new parent. This function can have unintended consequences. The specifics of what exact elements are being copied is important.]],
	arguments = {
		{ name = "to", type = "tes3uiElement", description = "Where to create the copy." },
		{ name = "copyChildren", type = "boolean", default = true, description = "If true, all children will also be copied to the newly created element." },
		{ name = "copyProperties", type = "boolean", default = true, description = "If true, all properties will be copied to the newly created element." },
	},
	returns = {
		{ name = "copy", type = "tes3uiElement", description = "The created copy." }
	}
}