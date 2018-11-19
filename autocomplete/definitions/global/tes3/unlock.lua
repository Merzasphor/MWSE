return {
	type = "function",
	description = [[Unlocks an object. Returns true if the object can be and wasn't already unlocked.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string" },
		},
	}},
	returns = "unlocked",
	valuetype = "boolean",
}