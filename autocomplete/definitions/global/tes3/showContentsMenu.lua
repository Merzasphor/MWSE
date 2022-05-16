return {
	type = "function",
	description = [[This function opens the contents menu. This menu is used for containers, companion inventories, and pickpocket attempts.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference|string", description = "The reference to open the contents of." },
			{ name = "pickpocket", type = "boolean", default = false, description = "If true, the contents menu will open in the context of an attempted pickpocketing." },
		},
	}},
	returns = {
		{ name = "wasShown", type = "boolean", description = "If true, the contents menu was successfully shown." },
	}
}