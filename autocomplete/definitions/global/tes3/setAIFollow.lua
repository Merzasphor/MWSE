return {
	type = "function",
	description = [[Configures a mobile actor to follow another actor to a destination.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference" },
			{ name = "target", type = "tes3reference|tes3mobileActor" },
			{ name = "destination", type = "tes3vector3|table", optional = true },
			{ name = "duration", type = "number", optional = true },
			{ name = "cell", type = "tes3cell|string", optional = true },
			{ name = "reset", type = "boolean", default = true },
		},
	}},
}