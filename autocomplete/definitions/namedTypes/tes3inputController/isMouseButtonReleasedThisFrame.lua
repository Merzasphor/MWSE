return {
	type = "method",
	description = [[Returns true if a mouse button was down last frame, and up this frame.]],
	arguments = {
		{ name = "button", type = "number", description = "The mouse button to test. Must be between `0` and `7`. Left mouse button is `0`, right is `1`, and middle is `2`." },
	},
	valuetype = "boolean",
}