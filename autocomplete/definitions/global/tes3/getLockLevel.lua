return {
	type = "function",
	description = [[Gets an locked reference's lock level. If no lock data is available, it will return nil.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string" },
		},
	}},
	returns = "level",
	valuetype = "number",
}