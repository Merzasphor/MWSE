return {
	type = "function",
	description = [[Use [`tes3.cast()`](https://mwse.github.io/MWSE/apis/tes3/#tes3cast) instead. Wrapper for the `ExplodeSpell` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "spell", type = "tes3spell|string" },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
