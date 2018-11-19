return {
	type = "function",
	description = [[Determines if a given reference is a locked door or container.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string" },
		},
	}},
	returns = "isLocked",
	valuetype = "boolean",
}