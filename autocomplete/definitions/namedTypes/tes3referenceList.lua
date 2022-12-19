return {
	type = "class",
	description = [[A collection for references, holding a cell and a linked list of references contained in the cell.]],
	examples = {
		["..\\..\\tes3cell\\actors\\convert"] = {
			title = "Converting reference list to array style table",
			description = "An example is given of a general function that can be used to convert a tes3referenceList to simple array which can be looped over with standard ipairs()."
		},
		["..\\..\\tes3cell\\actors\\genericIterator"] = {
			title = "Generic iterator function",
			description = "In this more involved example, we used the corouting API from the Lua standard library to construct a generic iterator function. The iterReferenceList() function can then be used directly inside a for loop."
		}
	}
}