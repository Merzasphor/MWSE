return {
	type = "function",
	description = [[Configures a mobile actor to travel to a destination.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference" },
			{ name = "destination", type = "tes3vector3|table" },
			{ name = "reset", type = "boolean", optional = true, default = true },
		},
	}},
}