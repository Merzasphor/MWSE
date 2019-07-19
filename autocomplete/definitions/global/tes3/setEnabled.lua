return {
	type = "function",
	description = [[Enables or disables a reference.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The reference to enable/disable.", },
			{ name = "toggle", type = "boolean", default = false, description = "If true, the enabled state will be toggled.", },
			{ name = "enabled", type = "boolean", default = true, description = "If not toggling, will set true to enable or false to disable.", },
		},
	}},
	returns = "success",
	valuetype = "boolean",
}