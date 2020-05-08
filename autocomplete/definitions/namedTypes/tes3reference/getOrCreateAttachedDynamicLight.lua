return {
	type = "method",
	description = [[Fetches the dynamic light attachment. If there isn't one, a new one will be created with the given light and value.]],
	arguments = {
		{ name = "light", type = "niPointLight" },
		{ name = "value", type = "number" },
	},
	valuetype = "tes3lightNode",
}