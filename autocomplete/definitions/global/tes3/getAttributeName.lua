return {
	type = "function",
	description = [[Returns the lowercase identifying name of an attribute for a given numerical, 0-based index. E.g. "strength".]],
	arguments = {
		{ name = "attributeId", type = "number", description = "The attribute id to get the name of, from tes3.attributeName constants." }
	},
	returns = "name",
	valuetype = "string",
}