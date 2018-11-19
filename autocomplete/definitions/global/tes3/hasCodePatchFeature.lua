return {
	type = "function",
	description = [[Attempts to determine if a given Morrowind Code Patch feature is enabled. This may not be possible, in which case nil will be returned.]],
	arguments = {
		{ name = "id", type = "number" }
	},
	returns = "state",
	valuetype = "boolean|nil",
}