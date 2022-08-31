return {
	type = "function",
	description = [[Plays the sound responsible for picking up or putting down an item.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The reference to attach the sound to.", optional = true },
			{ name = "item", type = "tes3item" },
			{ name = "pickup", type = "boolean", optional = true, default = true, description = "If false, the place down item will be used." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
