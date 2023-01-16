return {
	type = "method",
	description = [[Returns a normalized copy of this quaternion. The quaternion will be all zero if the quaternion magnitude is very near to zero and cannot be normalized.]],
	returns = {
		{ name = "result", type = "niQuaternion", description = "The normalized quaternion." },
	},
}
