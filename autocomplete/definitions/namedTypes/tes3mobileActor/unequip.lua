return {
	type = "method",
	description = [[Unequips one or more items from the actor.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "item", type = "tes3item|string", optional = true, description = "The item to unequip." },
			{ name = "type", type = "number", optional = true, description = "The item type to unequip. Only used if no other parameter is provided." },
			{ name = "armorSlot", type = "number", optional = true, description = "The armor slot to unequip." },
			{ name = "clothingSlot", type = "number", optional = true, description = "The clothing slot to unequip." },
		}
	}},
	returns = "itemUnequipped",
	valuetype = "boolean",
}