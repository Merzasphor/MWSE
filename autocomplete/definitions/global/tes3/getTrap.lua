return {
	type = "function",
	description = [[Gets the trap on a given reference.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string" },
		},
	}},
	returns = "spell",
	valuetype = "tes3spell",
}