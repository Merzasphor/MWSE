return {
	type = "function",
	description = [[Positions a reference to another place.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "cell", type = "tes3cell" },
			{ name = "orientation", type = "tes3vector3|table" },
			{ name = "position", type = "tes3vector3|table" },
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", default = "tes3.mobilePlayer", description = "The reference to attach the sound to." },
			{ name = "teleportCompanions", type = "boolean", default = true, description = "If used on the player, determines if companions should also be teleported." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
