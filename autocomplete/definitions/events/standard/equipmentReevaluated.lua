return {
	type = "event",
	description = [[The **equipmentReevaluated** event fires after an actor has gone through its items and determined if anything in its inventory is better than what it currently has equipped. This event can be used to force equip new, custom equipment slots if needed.]],
	related = { "equip", "equipped", "unequipped" },
	eventData = {
		reference = {
			type = "tes3reference",
			readOnly = true,
			description = "The reference that has reevaluated their equipment.",
		},
		actor = {
			type = "tes3actor",
			readOnly = true,
			description = "The actor that has reevaluated their equipment.",
		},
		mobile = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor that has reevaluated their equipment.",
		},
	},
	filter = "item",
}
