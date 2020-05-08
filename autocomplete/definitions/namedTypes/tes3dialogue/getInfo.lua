return {
	type = "method",
	description = [[Fetches the info that a given actor would produce for the dialogue.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "actor", type = "tes3mobileActor|tes3reference|string" },
		}
	}},
	valuetype = "tes3dialogueInfo",
}