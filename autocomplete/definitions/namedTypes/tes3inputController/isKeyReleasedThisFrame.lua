return {
	type = "method",
	description = [[Checks to see if a given scan code is released, and was pressed last frame.]],
	arguments = {
		{ name = "key", type = "number", description = "The scan code to test. Constants available through `tes3.scanCode`." },
	},
	valuetype = "boolean",
}