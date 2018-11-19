return {
	type = "function",
	description = [[Triggers an event. This can be used to trigger custom events with specific data.]],
	arguments = {
		{ name = "eventId", type = "string" },
		{ name = "payload", type = "table", optional = true },
		{ name = "options", type = "table", optional = true },
	},
}