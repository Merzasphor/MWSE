return {
	type = "function",
	description = [[Configures a mobile actor to wander around a cell.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference" },
			{ name = "idles", type = "table" },
			{ name = "range", type = "number", optional = true },
			{ name = "duration", type = "number", optional = true },
			{ name = "time", type = "number", optional = true },
			{ name = "reset", type = "boolean", default = true },
		},
	}},
}