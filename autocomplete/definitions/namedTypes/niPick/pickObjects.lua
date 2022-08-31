return {
	type = "method",
	description = [[Performs the picking operation by casting a ray.]],
	arguments = {
		{ name = "origin", type = "tes3vector3", description = "The origin of the ray in world coordinates." },
		{ name = "direction", type = "tes3vector3" },
		{ name = "append", type = "boolean", optional = true, default = false, description = "This parameter indicates whether the new results are appended to the results array, or if a new array is formed clearing the results array." },
		{ name = "maxDistance", type = "number", optional = true, description = "Default value: 0.0F" },
	},
}