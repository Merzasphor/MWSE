return {
	type = "function",
	description = [[Shallowly copies a table's contents to a destination table. If no destination table is provided, a new table will be created. Note that sub tables will not be copied, and will still refer to the same data.]],
	arguments = {
		{ name = "from", type = "table" },
		{ name = "to", type = "table", optional = true },
	},
	valuetype = "table",
}