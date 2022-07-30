return {
	type = "function",
	description = [[Creates a new NiPixelData object.]],
	arguments = {
		{ name = "width", type = "number" },
		{ name = "height", type = "number" },
		{ name = "mipMapLevels", type = "number", optional = true, default = 1 }
	},
	returns = {{ name = "pixelData", type = "niPixelData" }}
}