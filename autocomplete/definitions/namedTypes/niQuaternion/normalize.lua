return {
	type = "method",
	description = [[Normalizes the quaternion to unit length in-place. Returns true if result is unit length, false if the quaternion magnitude is very near to zero and cannot be normalized.]],
	returns = {
		{ name = "isNormalized", type = "boolean", description = "If the quaternion was successfully normalized." },
	},
}
