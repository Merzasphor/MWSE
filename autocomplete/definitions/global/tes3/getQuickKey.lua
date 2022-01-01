return {
	type = "function",
	description = [[This function retrieves data for a quick key.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "slot", type = "number", description = "The key to retrieve data for. This is a value between 1 and 9." },
		},
	}},
	valuetype = "tes3quickKey",
}