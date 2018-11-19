return {
	type = "function",
	description = [[Wrapper for the AddSoulGem mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "creature", type = "tes3creature|string", description = "The creature to be stored in the soul gem." },
			{ name = "soulgem", type = "tes3misc|string", description = "The soul gem to store the soul in." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
