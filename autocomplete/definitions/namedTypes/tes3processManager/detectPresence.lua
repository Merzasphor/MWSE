return {
	type = "function",
	description = [[This function performs a check for presence of a given mobile actor.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "actor", type = "tes3mobileActor", description = "The actor to perform a check for." },
			{ name = "unknown", type = "boolean" },
		},
	}},
	valueType = "boolean"
}
