return {
	type = "function",
	description = [[Returns the lowercase identifying name of a specialization type for a given numerical, 0-based index. E.g. "magic", by using GMSTs. Uses `tes3.specializationName` enumeration as a fallback.]],
	arguments = {
		{ name = "specializationId", type = "number", description = "Maps to [`tes3.specialization`](https://mwse.github.io/MWSE/references/specializations/) enumeration." }
	},
	returns = {{ name = "name", type = "string" }},
}