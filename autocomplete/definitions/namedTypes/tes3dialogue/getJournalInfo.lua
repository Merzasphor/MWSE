return {
	type = "method",
	description = [[Retrieves the info object for a journal. By default this will return the info for the player's current journal index for this dialogue. An index can be provided to fetch a specific index's related info.]],
	arguments = {
		{ name = "index", type = "number", optional = true, description = "The index of the journal to fetch the info for. If not provided, the current player's journal index is used." },
	},
	returns = {
		{ name = "journalInfo", type = "tes3dialogueInfo" },
	}
}