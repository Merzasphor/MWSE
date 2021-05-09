return {
	type = "method",
	description = [[Fetches the dynamic light attachment. If there isn't one, a new one will be created with the given light and value.

    The point light will be positioned as a child of the "attachLight" subnode of the model, or a child of the scene node if "attachLight" is not found. If no light is supplied as an argument, a point light of radius 512 will be automatically created.]],
	arguments = {
		{ name = "light", type = "niPointLight", optional = true },
		{ name = "phase", type = "number", optional = true },
	},
	valuetype = "tes3lightNode",
}