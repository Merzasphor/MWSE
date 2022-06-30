return {
	type = "function",
	description = [[Returns the lowercase identifying name of an attribute for a given numerical, 0-based index. E.g. "strength", by using GMSTs. Uses `tes3.attributeName` enumeration as a fallback.]],
	arguments = {
		{ name = "attributeId", type = "number", description = "The attribute id to get the name of. Maps to values in [`tes3.attribute`](https://mwse.github.io/MWSE/references/attributes/) namespace." }
	},
	returns = {{ name = "name", type = "string" }},
}