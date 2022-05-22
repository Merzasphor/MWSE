return {
	type = "method",
	description = [[Properties are named variables attached to an element. Sets a property value with `propName` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties. The callback is an address inside Morrowind.exe that will be called when the appropriate callback is invoked.]],
	arguments = {
		{ name = "propName", type = "string", description = "The property name." },
		{ name = "value", type = "number", description = "The value to set." },
	},
}