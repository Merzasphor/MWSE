return {
	type = "event",
	description = "This event is triggered when the game is about to play a sound from an item. Can be blocked to play custom sound instead.",
	eventData = {
		["item"] = {
			type = "tes3baseObject",
			readOnly = true,
			description = "The item for which the sound is about to be played.",
		},
		["state"] = {
			type = "number",
			readOnly = true,
			description = "Maps to values in [tes3.itemSoundState](https://mwse.github.io/MWSE/references/item-sound-states/) namespace.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The actor reference that picked or dropped the item that's now about to play the sound.",
		},
	},
	filter = "item",
	blockable = true,
}
