return {
	type = "method",
	description = [[Calculates a spherical linear interpolation between this quaternion and another, limited to a maximum rotation angle.]],
	arguments = {
		{ name = "target", type = "niQuaternion", description = "The quaternion to interpolate towards." },
		{ name = "rotationLimit", type = "number", description = "The interpolation result will be limited to this maximum angle from the initial quaternion. Angle in radians." },
	},
	returns = {
		{ name = "result", type = "niQuaternion", description = "The calculated result." },
	},
}
