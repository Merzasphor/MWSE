return {
	type = "function",
	description = [[Configures a mobile actor to escort another actor to a destination. Escorting actor will protect and wait for the escortee to catch up. Its advisible to make the `target` actor follow the escorting actor with `tes3.setAIFollow()`, because the escorting actor will otherwise wait the escortee forever.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference", description = "The escorting actor." },
			{ name = "target", type = "tes3reference|tes3mobileActor", description = "The actor being escorted." },
			{ name = "destination", type = "tes3vector3|table" },
			{ name = "duration", type = "number", optional = true, default = 0, description = "How long the escorter will do the escorting, in hours." },
			{ name = "cell", type = "tes3cell|string", optional = true },
			{ name = "reset", type = "boolean", optional = true, default = true },
		},
	}},
}