return {
	type = "function",
	description = [[Removes and deletes item data from a given reference, or from their inventory. If no `itemData` is provided, it will be removed from the reference itself.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "from", type = "tes3reference|tes3mobileActor|string", description = "The reference or mobile whose inventory will be modified." },
			{ name = "item", type = "tes3item|string", description = "The item to remove item data for." },
			{ name = "itemData", type = "tes3itemData", optional = true, description = "The exact item data to remove. If no itemData is provided, the itemData from the reference itself will be removed." },
			{ name = "force", type = "boolean", default = false, description = "If true, no checks are made to see if the item data should be deleted. It will always be purged." },
			{ name = "ignoreOwnership", type = "boolean", default = true, description = "If `force` is false, a check will be made to see if the item data is empty and can be deleted. By default this ignores any ownership data. Setting this to false will override that behavior." },
			{ name = "updateGUI", type = "boolean", default = true, description = "If false, the player or contents menu won't be updated." },
		},
	}},
	returns = {
		{ name = "wasRemoved", type = "boolean" }
	},
}
