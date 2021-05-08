return {
	type = "function",
	description = [[Signals looping animations on the actor to stop looping and play to the end.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference|string", description = "The reference to the actor." },
		},
	}},
}
