return {
	type = "function",
	description = [[Unregisters a function  event is raised.]],
	arguments = {
		{ name = "eventId", type = "string" },
		{ name = "callback", type = "function" },
		{ name = "options", type = "table", optional = true },
	},
}