return {
	type = "method",
	description = [[Calculates the starting velocity of a jump.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{name = "direction", type = "tes3vector2", optional = true, description = "The ground direction vector used to calculate the velocity. If not specified, a zero-length direction vector for a regular jump without movement will be used."},
		},
	}},
	valuetype = "tes3vector3",
}
