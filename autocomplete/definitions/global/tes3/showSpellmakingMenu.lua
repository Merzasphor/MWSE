return {
	type = "function",
	description = [[This function opens the spellmaking menu and returns true on success.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "serviceActor", type = "tes3mobileActor|tes3reference|string", optional = true, description = "The actor to use for calculating the service price. If none is provided, an open dialog menu's service actor will be used instead." },
			{ name = "useDialogActor", type = "boolean", default = true, description = "If set to false, the dialog menu service actor will be ignored. If false, a serviceActor must be provided." },
		},
	}},
	returns = "success",
	valuetype = "boolean",
}
