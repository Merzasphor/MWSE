return {
	type = "method",
	description = "Gets the index used by a particular value.",
	arguments = {
		{ name = "value", type = "any", description = "The value to search for." },
	},
	returns = {
		{ name = "index", type = "number", description = "The found index matching the value." },
	},
}
