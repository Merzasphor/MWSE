return {
	type = "method",
	description = [[Detaches and returns a property from the object which matches the given property type.]],
	arguments = {
		{ name = "type", type = "integer", description = "The types are available in [`ni.propertyType`](https://mwse.github.io/MWSE/references/ni/property-types/) table." },
	},
	valuetype = "niProperty",
}