return {
	type = "function",
	description = [[Use [`tes3reference:activate()`](https://mwse.github.io/MWSE/types/tes3reference/#activate) or [`tes3.setAIActivate()`](https://mwse.github.io/MWSE/apis/tes3/#tes3setaiactivate) instead. Wrapper for the `Activate` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
		},
	}},
}
