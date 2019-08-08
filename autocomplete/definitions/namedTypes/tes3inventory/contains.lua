return {
	type = "method",
	description = "Checks to see if the inventory contains an item.",
	arguments = {
		{ name = "item", type = "tes3item|string", description = "The item to check for." },
		{ name = "itemData", type = "tes3itemData", optional = true, description = "If provided, it will check for the specific data as well." },
	},
	valuetype = "boolean",
}