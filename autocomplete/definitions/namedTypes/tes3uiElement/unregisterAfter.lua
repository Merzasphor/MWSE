return {
	type = "method",
	description = [[Unregisters a function previously registered using `:registerAfter`.]],
	arguments = {
		{ name = "eventID", type = "string", description = "The event id." },
		{ name = "callback", type = "function", description = "The callback function." },
	},
	returns = {
		{ name = "wasUnregistered", type = "boolean" },
	},
}