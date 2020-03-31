return {
	description = "This event fires when a trap is being disarmed.",
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
		["disarmer"] = {
			type = "tes3mobileNpc",
			readonly = true,
			description = "The Mobile NPC doing the disarming.",
		},
		["tool"] = {
			type = "tes3item",
			readonly = true,
			description = "The item the disarmer is using to disarm the trap.",
		},
		["toolItemData"] = {
			type = "tes3itemData",
			readonly = true,
			description = "The item data for the tool.",
		},
		["chance"] = {
			type = "number",
			readonly = true,
			description = "The chance the trap disarm will be successful.",
		},
		["trapPresent"] = {
			type = "bool",
			readonly = true,
			description = "Indicates if a trap is present on the reference.",
		},
	}
}