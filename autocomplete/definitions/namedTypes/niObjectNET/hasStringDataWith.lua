return {
	type = "method",
	description = [[Searches for an niExtraData on this object to see if it has niStringExtraData that contains the provided `value` argument in its string field. Returns true if the value was found.]],
	arguments = {
		{ name = "value", type = "string", description = "The value to search for." },
	},
	returns = {
		{ name = "result", type = "boolean" },
	},
}
