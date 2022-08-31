return {
	type = "method",
	description = "Fills this matrix with the values needed to rotate a 3-by-1 vector or 3-by-N matrix of vectors around the Y axis by `y` radians. For the rotation matrix A and vector v, the rotated vector is given by A * v.",
	arguments = {
		{ name = "y", type = "number", description = "In radians." },
	},
}