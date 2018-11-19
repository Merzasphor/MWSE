return {
	type = "function",
	description = [[Removes a sound that is active.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "sound", type = "tes3sound|string" },
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", optional = true },
		},
	}},
}
