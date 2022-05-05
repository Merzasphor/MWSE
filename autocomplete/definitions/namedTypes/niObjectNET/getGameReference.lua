return {
	type = "method",
	description = [[Searches for an niExtraData on this object to see if it has one that holds a related reference.]],
	arguments = {
		{ name = "searchParents", type = "boolean", default = false, description = "If true, all parent objects (if applicable) are also searched." },
	},
	returns = {
		{ name = "reference", type = "tes3reference?" },
	},
}
