return {
	type = "operator",
	overloads = {
		{ rightType = "tes3matrix33", resultType = "tes3matrix33" },
		{ rightType = "tes3vector3", resultType = "tes3vector3" },
		{ rightType = "number", resultType = "tes3matrix33" },
	}
}
