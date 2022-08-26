return {
	type = "function",
	description = [[Registers a function to be called when an event is raised.]],
	arguments = {
		{ name = "eventId", type = "string" },
		{ name = "callback", type = "function" },
		{
			name = "options",
			type = "table",
			optional = true,
			tableParams = {
				{ name = "doOnce", type = "boolean", optional = true, default = false, description = "If this option is set to `true`, the function registered will be executed only once, and automatically unregistered thereafter." },
				{ name = "filter", type = "userdata|string|number", optional = true, description = "This parameter allows selectively executing the callback function only when a specific condition is met. The exact behavior depends on each event." }, --try other types: "userdata|any"...
				{ name = "priority", type = "number", optional = true, description = "Event callback with higher priority is executed before callback with lower priority. Typically used to make certain mods compatible." }
			}
		},
	},
}