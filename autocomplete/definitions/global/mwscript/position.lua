return {
	type = "function",
	description = [[Set [`tes3reference.position`](https://mwse.github.io/MWSE/types/tes3reference/#position) or [`tes3mobileActor.position`](https://mwse.github.io/MWSE/types/tes3mobileActor/#position) to desired new position instead, or use [`tes3.positionCell()`](https://mwse.github.io/MWSE/apis/tes3/#tes3positioncell). Wrapper for the `Position` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "cell", type = "string" },
			{ name = "x", type = "number", default = 0 },
			{ name = "y", type = "number", default = 0 },
			{ name = "z", type = "number", default = 0 },
			{ name = "rotation", type = "number", default = 0 },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
