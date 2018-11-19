return {
	type = "function",
	description = [[Registers a function to be called when an event is raised.]],
	arguments = {
		{ name = "eventId", type = "string" },
		{ name = "callback", type = "function" },
		{ name = "options", type = "table", optional = true },
	},
}