return {
	type = "function",
	description = [[When used in a mouse event, causes the element to capture further mouse events even when the cursor goes outside the element.]],
	arguments = {
		{ name = "capture", type = "boolean", description = "Turns on mouse capture for the element currently processing a mouse event if true, sending all further mouse events to that element. Turns off capture if false." },
	},
	examples = {
		["BasicUsage"] = {
			title = "Basic Usage",
			description = "Using the UI event system, cause a given element to capture the mouse drag.",
		},
	},
}
