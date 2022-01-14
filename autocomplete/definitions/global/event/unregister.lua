return {
	type = "function",
	description = [[Unregisters a function previously registered for an event with `event.register()`.]],
	arguments = {
		{ name = "eventId", type = "string" },
		{ name = "callback", type = "function" },
		{ name = "options", type = "table", optional = true },
	},
}