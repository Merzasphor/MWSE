return {
	type = "method",
	description = "Searches for an item stack in the inventory.",
	arguments = {
		{ name = "item", type = "tes3item|string", description = "The item to search for." },
		{ name = "itemData", type = "tes3itemData", optional = true, description = "If provided, it will check for the specific data as well." },
	},
	valuetype = "tes3itemStack",
}