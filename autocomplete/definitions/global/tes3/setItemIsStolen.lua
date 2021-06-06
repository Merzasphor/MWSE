return {
	type = "function",
	description = [[This function changes item's stolen flag.]],
	arguments = {
		{ name = "item", type = "tes3item", description = "The item whose stolen flag to modify." },
		{ name = "from", type = "tes3baseObject", description = "The location the item is stolen from." },
		{ name = "stolen", type = "boolean", optional = true, default = true, description = "If this parameter is set to true, the item will be flagged as stolen. Otherwise, the item's stolen flag will be removed." },
	},
}
