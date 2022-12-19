return {
	type = "method",
	description = [[Sets a property value with `prop` as the property key. Properties are named variables attached to an element. Gets a property value with `propName` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties.]],
	arguments = {
		{ name = "property", type = "number|string", description = "The property to get." },
		{ name = "value", type = "any", description = "The value to set." },
	},
}
