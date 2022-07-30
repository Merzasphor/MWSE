return {
	type = "method",
	description = [[Returns the height of the mipmap level at the given index, where level 0 is the finest (largest) mipmap level, and level `mipMapLevels - 1` is the coarsest (smallest) mipmap level.]],
	arguments = {
		{ name = "mipMapLevel", type = "number", optional = true, default = 0 },
	},
	valuetype = "number",
}