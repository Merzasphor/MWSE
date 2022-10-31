return {
	type = "value",
	description = [[Access to the script context for this reference and its associated script.]],
	readOnly = true,
	valuetype = "tes3scriptContext",
	examples = {
		["hasCompanionShare"] = {
			title = "Checking reference's script variables",
			description = "Companions usually have a mwscript script with variable named `companion` set to 1. This can be used to determine if a reference is player's companion or not.",
		}
	}
}