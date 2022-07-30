return {
	type = "method",
	description = [[Sets the pixel data from float data.]],
	arguments = {
		{ name = "data", type = "number[]", description = "The float data to be set to (1-indexed). The values should be in range [0.0, 1.0]." },
		{ name = "mipMapLevel", type = "number", optional = true, default = 0, description = "The mipmap level whose data to modify. The finest (largest) mipmap level is level 0." },
	},
}