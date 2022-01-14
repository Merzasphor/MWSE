return {
	type = "function",
	description = [[Enables or disables a reference.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The reference to enable/disable.", },
			{ name = "toggle", type = "boolean", default = false, description = "If true, the enabled state will be toggled.", },
			{ name = "enabled", type = "boolean", default = true, description = "If not toggling, setting `enabled` to true will enable the reference or to false will disable the reference.", },
		},
	}},
	returns = "success",
	valuetype = "boolean",
}