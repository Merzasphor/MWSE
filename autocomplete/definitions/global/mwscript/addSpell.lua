return {
	type = "function",
	description = [[Use [`tes3.addSpell()`](https://mwse.github.io/MWSE/apis/tes3/#tes3addspell) or [`tes3spellList:add()`](https://mwse.github.io/MWSE/types/tes3spellList/#add) instead. Wrapper for the `AddSpell` mwscript function.]],
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
