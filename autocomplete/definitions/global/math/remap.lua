return {
	type = "function",
	description = "Returns a value, scaled from expected values [lowIn, highIn] to [lowOut, highOut].\n\nFor example, a value of 7 remapped from [0,10] to [0,100] would be 70.",
	arguments = {
		{ name = "value", type = "number" },
		{ name = "lowIn", type = "number" },
		{ name = "highIn", type = "number" },
		{ name = "lowOut", type = "number" },
		{ name = "highOut", type = "number" },
	},
	valuetype = "number",
}