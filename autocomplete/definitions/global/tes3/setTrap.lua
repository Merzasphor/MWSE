return {
	type = "function",
	description = [[Sets the trap on a given reference.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string" },
			{ name = "spell", type = "tes3spell|string" },
		},
	}},
	returns = "trapped",
	valuetype = "boolean",
}