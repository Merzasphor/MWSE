return {
	type = "function",
	description = [[This function fetches reference's attached animation groups' timings.]],
	arguments = {
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference", description = "A reference whose animation groups' timings to fetch." },
		},
	},
	returns = "result",
	valuetype = "table",
}
