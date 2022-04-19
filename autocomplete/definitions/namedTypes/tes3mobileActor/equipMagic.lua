return {
	type = "method",
	description = [[Equips a spell or enchantment, optionally equipping the enchanted item if needed. Returns `false` if the item could not be equipped.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "source", type = "tes3spell|tes3item|string", description = [[The source of the magic to equip.

		Spells must be castable. Castable spells have a `castType` of `tes3.spellType.spell` or `tes3.spellType.power`. The actor is not required to know this spell.

		Items must have a castable enchantment. Castable enchantments have a `castType` of `tes3.enchantmentType.onUse` or `tes3.enchantmentType.castOnce`. The actor is not required to have this item in their inventory, unless `equipItem` is `true`.
]]
			},
			{ name = "itemData", type = "tes3itemData", optional = true, description = "Only valid if an item has been assigned to `source`. The item data of the specific item to equip." },
			{ name = "equipItem", type = "boolean", optional = true, default = false, description = "Only valid if an item has been assigned to `source`. If `true`, the item assigned to `source` will be equipped. Requires the actor to have the item in their inventory. If `false`, `itemData` must not be nil." },
			{ name = "updateGUI", type = "boolean", optional = true, default = true, description = "Only valid if this actor is the player. If `false`, the player GUI will not be updated to reflect the change to equipped magic." },
		}
	}},
	valuetype = "boolean",
}