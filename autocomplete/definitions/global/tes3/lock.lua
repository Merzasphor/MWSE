return {
	type = "function",
	description = [[Locks an object, and optionally sets a locked reference's lock level. Returns true if the object can be and wasn't already locked.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string" },
			{ name = "level", type = "number", optional = true }
		},
	}},
	returns = "locked",
	valuetype = "boolean",
}