return {
	type = "method",
	description = [[This method finds the info that contains the quest name, then loads and returns its text. This method accesses the disk, and may be slow to operate. For dialogues that aren't journal-based, this will be `nil`.]],
	returns = {
		{ name = "questName", type = "string|nil" },
	}
}