return {
	type = "method",
	description = [[Convenience method for checking the object's appCulled flag.]],
	arguments = {
		{
			name = "searchParents",
			type = "boolean",
			optional = true,
			default = false,
			description = "Check if the object is indirectly appCulled by a parent object.",
		},
	},
}
