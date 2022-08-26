return {
	type = "operator",
	overloads = {
		{ rightType = "tes3matrix44", resultType = "tes3matrix44", description = "The matrix multiplication. Geometrically, this will concatenate the transformations of both matrices in the resulting matrix." },
		{ rightType = "number", resultType = "tes3matrix44", description = "Multiplies the matrix by a scalar." },
	}
}
