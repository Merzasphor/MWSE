return {
	type = "method",
	description = [[Inverting or conjugating a rotation quaternion has the effect of reversing the axis of rotation, which modifies it to rotate in the opposite direction from the original. That is, if an object is rotated to a new position using a quaternion, then rotating it again by quaternion's inverse will return it to its original location.]],
	returns = {
		{ name = "result", type = "niQuaternion" }
	},
}
