return {
	type = "function",
	description = [[Returns an actor's current AI package ID, just as the mwscript function `GetCurrentAIPackage` would.]],
	arguments = {
		{ name = "reference", type = "tes3mobileActor|tes3reference" },
	},
	returns = "packageID",
	valuetype = "number",
}