return {
	type = "function",
	description = [[Use [`object.disabled`](https://mwse.github.io/MWSE/types/tes3baseObject/#disabled) on any object inheriting from `tes3baseObject`. Wrapper for the `GetDisabled` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
		},
	}},
	returns = "boolean",
}
