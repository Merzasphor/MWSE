return {
	type = "event",
	description = "This event is fired when an enchanted item has been created by the player.",
	eventData = {
		["baseObject"] = {
			type = "tes3item",
			readOnly = true,
			description = "The item originally enchanted.",
		},
		["object"] = {
			type = "tes3item",
			readOnly = true,
			description = "The newly created and enchanted item.",
		},
		["soul"] = {
			type = "tes3actor",
			description = "The actor used to enchant the item.",
		},
		["soulGem"] = {
			type = "tes3misc",
			description = "The soul gem used for the creation of the item.",
		},
		["enchanter"] = {
			type = "tes3mobile",
			description = "The mobile actor responsible for creating the enchantment.",
		},
		["enchanterReference"] = {
			type = "tes3reference",
			description = "The reference responsible for creating the enchantment.",
		},
	},
}
