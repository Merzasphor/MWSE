return {
	type = "value",
	description = [[One of the three reference collections for a cell.]],
	readOnly = true,
	valuetype = "tes3referenceList",
	examples = {
		["convert"] = {
			title = "Converting reference list to array style table",
			description = "An example is given of a general function that can be used to convert a tes3referenceList to simple array which can be looped over with standard ipairs()."
		},
		["genericIterator"] = {
			title = "Generic iterator function",
			description = "In this more involved example, we used the corouting API from the Lua standard library to construct a generic iterator function. The iterReferenceList() function can then be used directly inside a for loop."
		}
	}
}