return {
	type = "function",
	description = [[Configures a mobile actor to follow another actor to a destination.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference", description = "This is the actor that will follow another one." },
			{ name = "target", type = "tes3reference|tes3mobileActor", description = "The actor to follow." },
			{ name = "destination", type = "tes3vector3|table", optional = true },
			{ name = "duration", type = "number", optional = true, default = 0, description = "How long the follower will follow, in hours." },
			{ name = "cell", type = "tes3cell|string", optional = true },
			{ name = "reset", type = "boolean", optional = true, default = true },
		},
	}},
}