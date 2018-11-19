return {
	type = "function",
	description = [[Wrapper for the Disable mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "modify", type = "boolean", default = "true", description = "Set the object as modified." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
