return {
	type = "function",
	description = [[Unregisters a function previously registered for an event with `event.register()`.]],
	arguments = {
		{ name = "eventId", type = "string" },
		{ name = "callback", type = "function" },
		{
			name = "options",
			type = "table",
			optional = true,
			tableParams = {
				{ name = "filter", type = "userdata|string|number", optional = true, description = "If a callback function was registered with a filter, the same filter needs to be passed to `event.unregister` to successfully unregister the callback function." }, --try other types: "userdata|any"...
			}
		},
	},
}