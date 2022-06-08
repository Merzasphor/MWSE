return {
	type = "method",
	description = [[Properties are named variables attached to an element. Sets a property value with `property` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties. This function sets a property whose value is, itself, a property.]],
	arguments = {
		{ name = "property", type = "number|string", description = "The property to get." },
		{ name = "value", type = "number|string", description = "The value to set." },
	},
}
