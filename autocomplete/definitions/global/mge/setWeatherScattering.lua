return {
	type = "function",
	description = [[Sets distant land atmospheric scattering colours.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "outscatter", type = "table", description = "An array-style table with 3 numbers for red, green and blue color channels. The values can range from 0 to 1." },
			{ name = "inscatter", type = "table", description = "An array-style table with 3 numbers for red, green and blue color channels. The values can range from 0 to 1." }
		},
	}},
	returns = {{ name = "success", type = "boolean" }},
}