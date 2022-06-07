return {
	type = "function",
	description = [[Sets the in- and out-scatter values for MGE. The result table of `getScattering` can be modified then passed to this function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "inscatter", type = "tes3vector3|table" },
			{ name = "outscatter", type = "tes3vector3|table" },
		},
	}},
	returns = {
		{ name = "success", type = "table<string, number>" },
	},
}
