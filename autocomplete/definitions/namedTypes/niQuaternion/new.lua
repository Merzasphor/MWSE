return {
	type = "function",
	description = [[Creates a new niQuaternion object.]],
	arguments = {
		{ name = "w", type = "number", optional = true, default = 0 },
		{ name = "x", type = "number", optional = true, default = 0 },
		{ name = "y", type = "number", optional = true, default = 0 },
		{ name = "z", type = "number", optional = true, default = 0 },
	},
	returns = {{ name = "quaternion", type = "niQuaternion" }}
}