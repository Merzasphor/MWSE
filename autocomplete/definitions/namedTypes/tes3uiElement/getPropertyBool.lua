return {
	type = "method",
	description = [[Properties are extra variables attached to an element. Morrowind uses these to bind variables to the UI, and they can be useful for element class-specific properties. This function gets a property as a boolean value, defaulting to false if the property was not set.]],
	arguments = {
		{ name = "property", type = "number|string", description = "The property to get." },
	},
	returns = {
		{ name = "value", type = "boolean", description = "The value of the property, defaulting to false if the property was not set." },
	},
}
