return {
	type = "function",
	description = [[Creates an NiSourceTexture that represents the given image file name. The format preferences are saved in the texture and are passed to any renderer when the texture is loaded to that renderer. The format preferences are a request only, and may be ignored by any given renderer.]],
	arguments = {
		{ name = "path", type = "string", optional = false, description = "The filepath of the texture to load." },
	},
}