return {
	type = "method",
	description = [[Checks if the actor has provided item equipped.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "item", type = "tes3item|string", description = "The item to perform a check for." },
			{ name = "itemData", optional = true, type = "tes3itemData" },
		},
	}},
	returns = {
		{ name = "result", type = "boolean" },
	}
}
