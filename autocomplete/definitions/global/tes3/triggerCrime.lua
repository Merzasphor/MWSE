return {
	type = "function",
	description = [[Emulates the player committing a crime.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "criminal", type = "tes3mobileActor|tes3reference|string", default = "tes3.mobilePlayer" },
			{ name = "forceDetection", type = "boolean", default = false, description = "Can be set to true to ignore normal detection checks." },
			{ name = "type", type = "number", default = "tes3.crimeType.stealing", description = "Maps to [`tes3.crimeType`](https://mwse.github.io/MWSE/references/crime-types/) constants." },
			{ name = "value", type = "number", description = "Penalty for the crime. Defaults to 25 for pickpocketing." },
			{ name = "victim", type = "tes3mobileActor|tes3reference|string", default = "tes3.mobilePlayer" },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
