return {
	type = "event",
	description = "The journal event is invoked when a journal state progresses.",
	eventData = {
		index = {
			type = "number",
			readOnly = true,
			description = "The new index of the journal state.",
		},
		new = {
			type = "boolean",
			readOnly = true,
			description = "If true, the journal is newly added to the player. This effectively means that index has increased past 0.",
		},
		previousIndex = {
			type = "number",
			readOnly = true,
			description = "The previous index of the journal state.",
		},
		topic = {
			type = "tes3dialogue",
			readOnly = true,
			description = "The topic that dictates the journal entry.",
		},
		info = {
			type = "tes3dialogueInfo",
			readOnly = true,
			description = "The info for the newly set journal index.",
		},
		previousInfo = {
			type = "tes3dialogueInfo|nil",
			readOnly = true,
			description = "The info for the previously set journal index. If the journal entry is `new`ly added, this will be `nil`.",
		},
	},
}