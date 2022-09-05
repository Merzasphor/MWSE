return {
	type = "method",
	description = [[Gets an attached property by property type.]],
	arguments = {
		{ name = "type", type = "integer", description = "The types are available in [`ni.propertyType`](https://mwse.github.io/MWSE/references/ni/property-types/) table." },
	},
	valuetype = "niProperty",
}