return {
	type = "method",
	description = [[Equips an item, optionally adding the item if needed.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "item", type = "tes3item|string", description = "The item to equip." },
			{ name = "itemData", type = "tes3itemData", optional = true, description = "The item data to equip." },
			{ name = "forceSpecifiedItemData", type = "boolean", default = false, description = "If true, the first available itemData in the stack won't be chosen." },
			{ name = "addItem", type = "boolean", default = false, description = "If true, the item will be added to the actor's inventory if needed." },
		}
	}},
	valuetype = "boolean",
}