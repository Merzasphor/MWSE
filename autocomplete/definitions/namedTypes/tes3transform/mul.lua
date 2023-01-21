return {
	type = "operator",
	overloads = {
		{ rightType = "tes3transform", resultType = "tes3transform",
			description = "Calculate the combination of two transforms.", },
		{ rightType = "tes3vector3", resultType = "tes3vector3",
			description = "Calculate the result of applying this transform to a vector." },
	},
}
