return {
	description = "This event fires when a lock is being picked.",
	eventData = {
		["reference"] = {
			type = "tes3reference",
			readonly = true,
			description = "The reference that triggered the event (container, door, etc.).",
		},
		["lockData"] = {
			type = "tes3lockAttachmentNode",
			readonly = true,
			description = "The lock data of the reference.",
		},
		["picker"] = {
			type = "tes3mobileNpc",
			readonly = true,
			description = "The Mobile NPC doing the disarming.",
		},
		["tool"] = {
			type = "tes3item",
			readonly = true,
			description = "The item the picker is using to pick the lock.",
		},
		["toolItemData"] = {
			type = "tes3itemData",
			readonly = true,
			description = "The item data for the tool.",
		},
		["chance"] = {
			type = "number",
			readonly = true,
			description = "The chance the lockpick will be successful.",
		},
		["lockPresent"] = {
			type = "bool",
			readonly = true,
			description = "Indicates if a lock is present on the reference.",
		},
	}
}