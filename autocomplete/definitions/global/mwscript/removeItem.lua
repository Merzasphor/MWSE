return {
	type = "function",
	description = [[Use [`tes3.removeItem()`](https://mwse.github.io/MWSE/apis/tes3/#tes3removeitem), [`tes3.removeItemData()`](https://mwse.github.io/MWSE/apis/tes3/#tes3removeitemdata) or [`tes3inventory:removeItem()`](https://mwse.github.io/MWSE/types/tes3inventory/#removeitem) instead. Wrapper for the `RemoveItem` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "item", type = "tes3item|string", description = "The item to be added." },
			{ name = "count", type = "number", default = 1, description = "The number of items to be added." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
