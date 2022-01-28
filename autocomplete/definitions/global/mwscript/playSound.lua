return {
	type = "function",
	description = [[Use [`tes3.playSound()`](https://mwse.github.io/MWSE/apis/tes3/#tes3playsound), [`tes3sound:play()`](https://mwse.github.io/MWSE/types/tes3sound/#play) method, or [`tes3.playItemPickupSound()`](https://mwse.github.io/MWSE/apis/tes3/#tes3playitempickupsound) instead. Wrapper for the `PlaySound` mwscript function.]],
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
