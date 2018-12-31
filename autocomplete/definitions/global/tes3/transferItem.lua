return {
	type = "function",
	description = [[Moves one or more items from one reference to another. Returns the actual amount of items successfully transferred.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "from", type = "tes3reference|tes3mobileActor|string", description = "Who to take items from." },
			{ name = "to", type = "tes3reference|tes3mobileActor|string", description = "Who to give items to." },
			{ name = "item", type = "tes3item|string", description = "The item to transfer." },
			{ name = "itemData", type = "tes3itemData", optional = true, description = "The specific item data to transfer if, for example, you want to transfer a specific player item." },
			{ name = "count", type = "number", default = "1", description = "The maximum number of items to transfer." },
			{ name = "updateGUI", type = "boolean", default = true, description = "If false, the function won't manually resync the player's GUI state. This can result in some optimizations, though `tes3ui.forcePlayerInventoryUpdate()` must manually be called after all inventory updates are finished." },
		},
	}},
	returns = {{ name = "transferredCount", type = "number" }},
}
