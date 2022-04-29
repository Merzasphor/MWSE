return {
	type = "event",
	description = "This event is fired when an enchanted item could not be created.",
	eventData = {
		["baseObject"] = {
			type = "tes3item",
			readOnly = true,
			description = "The item originally enchanted.",
		},
		["soul"] = {
			type = "tes3actor",
			description = "The actor used to enchant the item.",
		},
		["soulGem"] = {
			type = "tes3misc",
			description = "The soul gem used for the failed creation of the item.",
		},
		["enchanter"] = {
			type = "tes3mobile",
			description = "The mobile actor responsible for failing to create the enchantment.",
		},
		["enchanterReference"] = {
			type = "tes3reference",
			description = "The reference responsible for failing to create the enchantment.",
		},
	},
}
