return {
	type = "function",
	description = [[This function opens the repair service menu.]],
	arguments = {{
		name = "params",
		type = "table",
		optional = true,
		tableParams = {
			{ name = "serviceActor", type = "tes3mobileActor|tes3reference|string", optional = true, default = "tes3mobilePlayer", description = "The actor to use for calculating the service price." },
		},
	}},
}