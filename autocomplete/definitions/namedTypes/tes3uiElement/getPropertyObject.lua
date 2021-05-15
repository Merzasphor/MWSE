return {
	type = "method",
	description = [[Properties are named variables attached to an element. Gets a property value with ``propName`` as the property key. Morrowind uses these to bind variables to the UI. Useful for element class-specific properties. Returns ``nil`` if the property key did not have data.
    
    For ``getPropertyObject``, an expected return value not derived from ``tes3baseObject`` requires the usertype to be provided as well. A return value derived from ``tes3baseObject`` should not provide the extra parameter.]],
	arguments = {
		{ name = "propName", type = "string", description = "The property name." },
		{ name = "expectedUsertype", type = "string", description = "A Lua usertype name, if expecting an unusual type.", optional = true },
	},
    valuetype = "object",
}