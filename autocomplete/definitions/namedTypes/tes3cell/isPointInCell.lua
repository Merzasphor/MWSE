return {
	type = "method",
	description = [[Determines if a given X/Y coordinate falls in the given cell. This will always be true for interior cells.]],
	arguments = {
		{ name = "x", type = "number", description = "The X position to test." },
		{ name = "y", type = "number", description = "The Y position to test." },
	},
	returns = {
		{ name = "inCell", type = "boolean", description = "true, if the point is found in the cell." },
	}
}