return {
	type = "function",
	description = [[Returns true for a function previously registered to an event with `event.register()`.]],
	arguments = {
		{ name = "eventId", type = "string" },
		{ name = "callback", type = "function" },
		{
			name = "options",
			type = "table",
			optional = true,
			tableParams = {
				{ name = "filter", type = "userdata|string|number", optional = true, description = "Allows searching for a callback function registered with the specified filter." }, --try other types: "userdata|any"...
			}
		},
	},
	valuetype = "boolean"
}