return {
	type = "method",
	description = [[Searches for an niExtraData on this object to see if it has niStringExtraData that has its string start with the provided `value` argument. Returns true if the value was found.]],
	arguments = {
		{ name = "value", type = "string", description = "The value to search for." },
	},
	returns = {
		{ name = "result", type = "boolean" },
	},
}
