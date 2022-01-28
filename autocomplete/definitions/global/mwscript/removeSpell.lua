return {
	type = "function",
	description = [[Use [`tes3.removeSpell()`](https://mwse.github.io/MWSE/apis/tes3/#tes3removespell) or [`tes3spellList:remove()`](https://mwse.github.io/MWSE/types/tes3spellList/#remove) instead. Wrapper for the `RemoveSpell` mwscript function.]],
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
