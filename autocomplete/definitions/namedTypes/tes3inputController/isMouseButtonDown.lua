return {
	type = "method",
	description = [[Returns the mouse down state for a given mouse button.]],
	arguments = {
		{ name = "button", type = "number", description = "The mouse button to test. Must be between `0` and `7`. Left mouse button is `0`, right is `1`, and middle is `2`." },
	},
	valuetype = "boolean",
}