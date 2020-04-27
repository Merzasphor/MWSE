return {
	type = "method",
	description = [[Performs the picking operation.  Forms an array of objects intersected by the ray defined by `origin` and `direction`.  This ray is in world coordinates.  The current PickType, SortType, IntersectType, and front-only mode determine the type of array formed.  The `append` parameter indicates whether the new results are appended onto those intersections already contained in the results array, or if a new array is formed clearing those results already contained in the results array.

    ]],
	arguments = {
		{ name = "origin", type = "tes3vector3" },
		{ name = "distance", type = "tes3vector3" },
		{ name = "append", type = "boolean", optional = true, description = "Default value: false" },
		{ name = "maxDistance", type = "number", optional = true, description = "Default value: 0.0F" },
	},
}