return {
	type = "function",
	description = [[Creates an NiSourceTexture from the given filepath.]],
	arguments = {
		{ name = "path", type = "string", optional = false, description = "The filepath of the texture to load." },
		{ name = "useCached", type = "boolean", default = true, description = "If true, the texture will be stored in the normal texture source cache, so that multiple calls to the same path will return the same object. This behavior can be disabled if necessary." },
	},
}