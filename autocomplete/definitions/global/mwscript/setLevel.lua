return {
	type = "function",
	description = [[Use [`tes3npc.level`](https://mwse.github.io/MWSE/types/tes3npc/#level) instead. Wrapper for the `SetLevel` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "level", type = "number" },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
