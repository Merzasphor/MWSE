return {
	type = "function",
	description = [[Use [`tes3.removeSound()`](https://mwse.github.io/MWSE/apis/tes3/#tes3removesound) or [`tes3sound:stop()`](https://mwse.github.io/MWSE/types/tes3sound/#stop) instead. Wrapper for the `StopSound` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "sound", type = "tes3sound|string" },
		},
	}},
	returns = "boolean",
}
