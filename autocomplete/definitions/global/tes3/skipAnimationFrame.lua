return {
	type = "function",
	description = [[Skips a given reference's animation for a single frame.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference|string", description = "The reference whose animation frame will be skipped." },
		},
	}},
}
