return {
	type = "method",
	description = [[Sets the pixel data from byte data.]],
	arguments = {
		{ name = "data", type = "number[]", description = "The byte data to be set to (1-indexed)." },
		{ name = "mipMapLevel", type = "number", optional = true, default = 0, description = "The mipmap level whose data to modify. The finest (largest) mipmap level is level 0." },
	},
}