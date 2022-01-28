return {
	type = "function",
	description = [[Use [`tes3actor:hasItemEquipped()`](https://mwse.github.io/MWSE/types/tes3actor/#hasitemequipped) or [`tes3.getEquippedItem()`](https://mwse.github.io/MWSE/apis/tes3/#tes3getequippeditem) instead. Wrapper for the `HasItemEquipped` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "item", type = "tes3item|string", description = "The item to check for." },
		},
	}},
	returns = "boolean",
}
