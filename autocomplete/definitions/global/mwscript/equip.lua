return {
	type = "function",
	description = [[Wrapper for the Equip mwscript function. Replacements: [`mobile:equip()`](https://mwse.github.io/MWSE/types/tes3mobileActor/#equip) or [`mobile.combatSession:changeEquipment()`](https://mwse.github.io/MWSE/types/tes3combatSession/#changeequipment).]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "item", type = "tes3item|string", description = "The item to be equipped." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
