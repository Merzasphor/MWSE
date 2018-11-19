return {
	type = "function",
	description = [[Sets a locked reference's lock level. This does not lock the object.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string" },
			{ name = "level", type = "number" }
		},
	}},
	returns = "set",
	valuetype = "boolean",
}