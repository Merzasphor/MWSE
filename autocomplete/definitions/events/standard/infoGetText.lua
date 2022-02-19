return {
	type = "event",
	description = "This event fires when a dialogue info object text is retrieved. That can be when starting a conversation with an NPC, a service was refused to the player, NPC's responses to player persuading them and if the subtitles are enabled, getting the text for the subtitle will also trigger `infoGetText` event.",
	related = { "infoGetText", "infoLinkResolve", "infoResponse", "infoFilter", "postInfoResponse" },
	eventData = {
		["text"] = {
			type = "string",
			description = "The text to return. This can be modified. Does not contain the original text. If not set, the original text will be used instead.",
		},
		["info"] = {
			type = "tes3dialogueInfo",
			readOnly = true,
			description = "The dialogue info object.",
		},
		["loadOriginalText"] = {
			type = "method",
			description = "Loads the original text for the info from the game files, bypassing this event.",
		},
	},
	filter = "info",
	examples = {
		["appendText"] = {
			title = "Append custom text to a greeting line."
		}
	}
}