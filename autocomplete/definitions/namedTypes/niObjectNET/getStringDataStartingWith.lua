return {
	type = "method",
	description = [[Searches for an niExtraData on this object to see if it has niStringExtraData that has its string start with the provided `value` argument.]],
	arguments = {
		{ name = "value", type = "string", description = "The first niStringExtraData starting with this value will be returned." },
	},
	returns = {
		{ name = "extra", type = "niStringExtraData?" },
	},
}
