return {
	type = "method",
	description = [[Fills this pixel data with the provided color.]],
	arguments = {
		{ name = "data", type = "number[]", description = "The color data to be set (1-indexed). The values should be in range [0.0, 1.0]. The first three values are RGB color channels, while the last one is alpha channel. The array length must be equal to the `bytesPerPixel` property of this niPixelData object, because alpha can be assigned only to the niPixelData object that has an alpha channel." },
		{ name = "mipMapLevel", type = "number", optional = true, default = 0, description = "The mipmap level to fill with the provided color. The finest (largest) mipmap level is level 0." },
	},
}