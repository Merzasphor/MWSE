return {
	type = "function",
	description = [[Drops one or more items from a reference's inventory onto the ground at their feet.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference|string", description = "The reference whose inventory will be modified." },
			{ name = "item", type = "tes3item|string", description = "The item to drop." },
			{ name = "itemData", type = "tes3itemData", optional = true, description = "The item data to match." },
			{ name = "count", type = "number", default = 1, description = "The number of items to drop." },
			{ name = "matchExact", type = "boolean", default = true, description = "If true, the exact item will be matched. This is important if you want to drop an item without item data." },
			{ name = "updateGUI", type = "boolean", default = true, description = "If false, the player or contents menu won't be updated." },
		},
	}},
	returns = {{ name = "createdReference", type = "tes3reference" }},
}
