return {
	type = "method",
	description = [[Attaches a property to this object, without checking to see if the property or another of its type is already on the list. Property lists must not have more than one property of a given class (i.e. no two niTexturingProperty objects) attached at once, or else undefined behavior will result.]],
	arguments = {
		{ name = "property", type = "niProperty" },
	},
}