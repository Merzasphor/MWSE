return {
	type = "method",
	description = [[Searches for an niExtraData on this object to see if it has niStringExtraData that has the provided `value` argument in its string field.]],
	arguments = {
		{ name = "value", type = "string", description = "The first niStringExtraData with this word will be returned." },
	},
	returns = {
		{ name = "extra", type = "niStringExtraData?" },
	},
}
