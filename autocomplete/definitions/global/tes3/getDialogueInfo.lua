return {
	type = "function",
	description = [[Locates and returns a Dialogue Info by a given id. This involves file IO and is an expensive call. Results should be cached.]],
	arguments = {
		{ name = "dialogue", type = "tes3dialogue|string", description = "The dialogue that the info belongs to." },
		{ name = "id", type = "string", description = "The numerical, unique id for the info object." },
	},
	returns = "dialogueInfo",
	valuetype = "tes3dialogueInfo",
}