return {
	type = "function",
	description = [[Use [`tes3mobileActor.isPlayerDetected`](https://mwse.github.io/MWSE/types/tes3mobileActor/#isplayerdetected) or depending on what you are doing, [`detectSneak`](https://mwse.github.io/MWSE/events/detectSneak/) event may be desirable. Wrapper for the `GetDetected` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "target", type = "tes3reference|tes3mobileActor|string", description = "Actor to check detection for." },
		},
	}},
	returns = "boolean",
}
