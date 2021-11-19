return {
	type = "function",
	description = [[This function performs a check whether a detector can detect another actor sneaking.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "detector", type = "tes3mobileActor", description = "The detector actor to perform a check for." },
			{ name = "target", type = "tes3mobileActor", description = "The target actor to perform a check for." },
			{ name = "unknown", type = "boolean" },
		},
	}},
	returns = {{ name = "isDetected", type = "boolean" }},
}
