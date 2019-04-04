return {
	type = "function",
	description = [[Configures a mobile actor to activate an object.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference" },
			{ name = "target", type = "tes3reference" },
			{ name = "reset", type = "boolean", default = true },
		},
	}},
}