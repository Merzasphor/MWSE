return {
	type = "method",
	description = [[Properties are extra variables attached to an element. Morrowind uses these to bind variables to the UI, and they can be useful for element class-specific properties. This function sets a property to a callback value, represented as a number. This function can be dangerous to use, and can lead to crashes if not properly understood.]],
	arguments = {
		{ name = "property", type = "number|string", description = "The property to set." },
		{ name = "value", type = "number", description = "The value to set." },
	},
}
