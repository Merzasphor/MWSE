return {
	type = "function",
	description = [[Wrapper for the PositionCell mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "cell", type = "string" },
			{ name = "x", type = "number", default = 0 },
			{ name = "y", type = "number", default = 0 },
			{ name = "z", type = "number", default = 0 },
			{ name = "rotation", type = "number", default = 0 },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
