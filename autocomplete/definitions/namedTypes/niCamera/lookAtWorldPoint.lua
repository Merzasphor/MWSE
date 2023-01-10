return {
	type = "method",
	description = [[Update the camera's local rotation so that it is looking at the given point, with an up vector as close as possible to the given up vector. Both parameters are assumed to be in world space.]],
	arguments = {
		{ name = "point", type = "tes3vector3" },
		{ name = "up", type = "tes3vector3" },
	},
}
