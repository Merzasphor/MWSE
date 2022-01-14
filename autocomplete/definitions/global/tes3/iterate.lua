return {
	type = "function",
	description = [[This function returns a function that iterates over a tes3iterator object. This is useful for for loops.
		
Note that tes3iterator objects support iteration with `pairs()` function.]],
	arguments = {
		{ name = "iterator", type = "tes3iterator" }
	},
	returns = "function",
	valuetype = "function",
}