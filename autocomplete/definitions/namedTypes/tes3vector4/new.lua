return {
	type = "function",
	description = [[Creates a new vector. If no parameters are provided, an empty set will be constructed.]],
	arguments = {
		{ name = "x", type = "number", optional = true },
		{ name = "y", type = "number", optional = true },
		{ name = "z", type = "number", optional = true },
		{ name = "w", type = "number", optional = true },
	},
	returns = {{ name = "vector", type = "tes3vector4" }},
}