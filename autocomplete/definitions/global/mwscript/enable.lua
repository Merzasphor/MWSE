return {
	type = "function",
	description = [[Wrapper for the Enable mwscript function. Replacements: [`tes3.setEnabled()`](https://mwse.github.io/MWSE/apis/tes3/#tes3setenabled) or [`reference:enable()`](https://mwse.github.io/MWSE/types/tes3reference/#enable).]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "modify", type = "boolean", default = "true", description = "Set the object as modified." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
