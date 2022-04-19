return {
	type = "method",
	description = [[Unequips the currently equipped magic, optionally unequipping the enchanted item if needed.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "unequipItem", type = "boolean", optional = true, default = false, description = "Only valid if the currently equipped magic is from an equippable item enchantment. If `true`, the item containing the enchantment will be unequipped." },
			{ name = "updateGUI", type = "boolean", optional = true, default = true, description = "Only valid if this actor is the player. If `false`, the player GUI will not be updated to reflect the change to equipped magic." },
		}
	}}
}