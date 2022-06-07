return {
	type = "function",
	description = [[Gets the in- and out-scatter values from MGE. These are returned in a table with the `inscatter` and `outscatter` keys. The result table can be modified, then sent back to `setScattering`.]],
	returns = {
		{ name = "scatters", type = "table<string, tes3vector3>" },
	},
}
