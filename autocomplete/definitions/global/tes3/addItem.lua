return {
	type = "function",
	description = [[Adds an item to a given reference's inventory or mobile's inventory.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "Who to give items to." },
			{ name = "item", type = "tes3item|tes3leveledItem|string", description = "The item to add. If a leveled item is passed, it will be resolved and added." },
			{ name = "itemData", type = "tes3itemData", optional = true, description = "The item data for the item." },
			{ name = "soul", type = "tes3creature|tes3npc", optional = true, description = "For creating filled soul gems." },
			{ name = "count", type = "number", default = "1", description = "The maximum number of items to add." },
			{ name = "playSound", type = "boolean", default = true, description = "If false, the up/down sound for the item won't be played." },
			{ name = "limit", type = "boolean", default = false, description = "If false, items can be placed into containers that shouldn't normally be allowed. This includes organic containers, and containers that are full." },
			{ name = "reevaluateEquipment", type = "boolean", default = true, description = "If true, and the item added is armor, clothing, or a weapon, the actor will reevaluate its equipment choices to see if the new item is worth equipping. This does not affect the player." },
			{ name = "updateGUI", type = "boolean", default = true, description = "If false, the function won't manually resync the player's GUI state. This can result in some optimizations, though [`tes3ui.forcePlayerInventoryUpdate()`](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uiforceplayerinventoryupdate) must manually be called after all inventory updates are finished." },
		},
	}},
	returns = {{ name = "addedCount", type = "number" }},
}
