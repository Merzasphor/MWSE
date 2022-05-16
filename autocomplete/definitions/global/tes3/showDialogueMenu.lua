return {
	type = "function",
	description = [[This function opens the dialogue menu. This behaves similar to the `ForceGreeting` mwscript command.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference|string", description = "The reference to open dialogue with." },
			{ name = "checkAllowWerewolfForceGreeting", type = "boolean", default = true, description = "If true, the `AllowWerewolfForceGreeting` variable must exist on the reference's script to allow opening a dialogue while the player is a werewolf. This can be set to false to override the vanilla behavior." },
		},
	}},
	returns = {
		{ name = "wasShown", type = "boolean", description = "If true, the dialogue window was successfully shown." },
	}
}