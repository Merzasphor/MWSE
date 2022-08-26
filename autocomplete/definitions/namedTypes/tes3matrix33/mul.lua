return {
	type = "operator",
	overloads = {
		{ rightType = "tes3matrix33", resultType = "tes3matrix33", description = "The matrix multiplication. Geometrically, this will concatenate the transformations of both matrices in the resulting matrix." },
		{ rightType = "tes3vector3", resultType = "tes3vector3", description = "Multiplies the matrix by a vector. The resulting vector is staring vector with the matrix' transformations applied." },
		{ rightType = "number", resultType = "tes3matrix33", description = "Multiplies the matrix by a scalar." },
	}
}
