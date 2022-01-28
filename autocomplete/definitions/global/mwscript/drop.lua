return {
	type = "function",
	description = [[Use [`tes3.dropItem()`](https://mwse.github.io/MWSE/apis/tes3/#tes3dropitem) or [`tes3inventory:dropItem()`](https://mwse.github.io/MWSE/types/tes3inventory/#dropitem) instead. Wrapper for the `Drop` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "item", type = "tes3item|string", description = "The item to be dropped." },
			{ name = "count", type = "number", default = 1, description = "The number of items to drop." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
