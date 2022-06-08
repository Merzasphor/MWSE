return {
	type = "method",
	description = [[Properties are extra variables attached to an element. Morrowind uses these to bind variables to the UI, and they can be useful for element class-specific properties. This function gets a property whose value is, itself, a property, defaulting to `0` if the property was not set.]],
	arguments = {
		{ name = "property", type = "number|string", description = "The property to get." },
	},
	returns = {
		{ name = "value", type = "number", description = "The value of the property, defaulting to `0` if the property was not set." },
	},
}
