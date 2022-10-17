return {
	type = "event",
	description = "This event is raised when an enchantment price is being determined.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor for who is offering the enchantment service. May not always be available.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "A shortcut to the mobile's reference. May not always be available.",
		},
		["basePrice"] = {
			type = "number",
			readOnly = true,
			description = "The base price of the enchantment, before any disposition or event modifications.",
		},
		["price"] = {
			type = "number",
			description = "The price of the enchantment. This can be modified.",
		},
		["item"] = {
			type = "tes3item",
			readOnly = true,
			description = "The item, if any, that is being enchanted.",
		},
		["itemData"] = {
			type = "tes3itemData",
			readOnly = true,
			description = "The item data for the enchanted item.",
		},
		["soulGem"] = {
			type = "tes3misc",
			readOnly = true,
			description = "The soul gem being used to make the enchantment.",
		},
		["soulGemData"] = {
			type = "tes3itemData",
			readOnly = true,
			description = "The soul gem's associated item data.",
		},
		["soul"] = {
			type = "tes3actor",
			readOnly = true,
			description = "The soul contained in the soul gem.",
		},
		["castType"] = {
			type = "number",
			readOnly = true,
			description = "The enchantment cast type. Maps to `tes3.enchantmentType.*`.",
		},
		["effects"] = {
			type = "table[]",
			readOnly = true,
			description = "An array of the effects being enchanted onto the item. This includes the `effect` object, `magnitudeLow`/`magnitudeHigh` values, the `area`, `duration`, and `range`. The `attribute` and `skill` values are available as appropriate.",
		},
	},
}
