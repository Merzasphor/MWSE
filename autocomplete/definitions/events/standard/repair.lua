return {
	type = "event",
	description = "This event is invoked when an item is being repaired. Currently, the event only fires when the player repairs an item.",
	eventData = {
		["repairer"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The actor performing the repair. Note that this is currently always the player, but this may change in future updates.",
		},
		["item"] = {
			type = "tes3item",
			readOnly = true,
			description = "The item being repaired.",
		},
		["itemData"] = {
			type = "tes3itemData",
			readOnly = true,
			description = "The item data relevant to the repaired item.",
		},
		["tool"] = {
			type = "tes3repairTool",
			readOnly = true,
			description = "The repair tool being used.",
		},
		["toolData"] = {
			type = "tes3itemData",
			readOnly = true,
			description = "The item data relevant to repair tool.",
		},
		["chance"] = {
			type = "number",
			description = "The percent chance of the repair being successful. This can be changed to modify the player's chance of repairing. It is not limited at 100.",
		},
		["repairAmount"] = {
			type = "number",
			description = "The amount of condition that will be restored to the item.",
		},
	},
}
