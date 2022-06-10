return {
	type = "function",
	description = [[This function is used for calculating relative access into an array, such that accessing an element one past the array's size will instead return the position of the first element. Providing an index one before the start (note that this is `0`, not `-1`) will instead give the index to the last element in the array.]],
	arguments = {
		{ name = "t", type = "table", description = "The table whose size will determine the new wrapped index." },
		{ name = "index", type = "number", description = "The initial provided index. If this is before or after the array, it will be cycled around." },
	},
	returns = {
		{ name = "index", type = "number" },
	}
}
