return {
	type = "function",
	description = [[]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "actorRef", type = "tes3reference", optional = true, default = "tes3player", description = "" },
			{ name = "callback", type = "function", optional = true, description = "" },
			{ name = "filter", type = "function|string", optional = true, description = "" },
			{ name = "title", type = "string", description = "" },
			{ name = "noResultsText", type = "string", optional = true, description = "" },
			{ name = "noResultsCallback", type = "function", optional = true, description = "" },
			{ name = "leaveMenuMode", type = "boolean", optional = true, description = "Is the menu going to be closed or open after closing Inventory Select Menu. By default, it will be in the state before this function was called." },
		},
	}},
}
