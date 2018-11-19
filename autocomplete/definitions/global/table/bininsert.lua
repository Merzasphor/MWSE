return {
	type = "function",
	description = [[Inserts a given value through BinaryInsert into the table sorted by [, comp].

If 'comp' is given, then it must be a function that receives two table elements, and returns true when the first is less than the second, e.g. comp = function(a, b) return a > b end, will give a sorted table, with the biggest value on position 1. [, comp] behaves as in table.sort(table, value [, comp]) returns the index where 'value' was inserted]],
	arguments = {
		{ name = "t", type = "table" },
		{ name = "value", type = "unknown" },
		{ name = "comp", type = "unknown", optional = true },
	},
	valuetype = "number",
}