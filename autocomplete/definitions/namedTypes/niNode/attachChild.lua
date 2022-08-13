return {
	type = "method",
	description = [[Attaches the child to the children list of the node. Doesn't check to see if the object is already in the child list.]],
	arguments = {
		{ name = "child", type = "niAVObject" },
		{ name = "useFirstAvailable", type = "boolean", optional = true, default = false, description = "Use the first available space in the list. If `false` appends the child at the end of the list." },
	},
}