return {
	type = "function",
	description = [[Returns true for a function previously registered to an event with `event.register()`.]],
	arguments = {
		{ name = "eventId", type = "string" },
		{ name = "callback", type = "function" },
		{ name = "options", type = "table", optional = true },
	},
	valuetype = "boolean"
}