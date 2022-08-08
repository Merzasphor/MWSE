return {
	type = "function",
	description = [[Creates a new vector. If no parameters are provided, an empty set will be constructed.]],
	arguments = {
		{ name = "x", type = "number", optional = true, default = 0 },
		{ name = "y", type = "number", optional = true, default = 0 },
		{ name = "z", type = "number", optional = true, default = 0 },
		{ name = "w", type = "number", optional = true, default = 0 },
	},
	returns = {{ name = "vector", type = "tes3vector4" }},
}