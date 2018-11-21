return {
	type = "function",
	description = [[Creates a timer that will finish the next frame. It defaults to the next simulation frame.]],
	arguments = {
		{ name = "callback", type = "function" },
		{ name = "type", type = "number", default = "timer.simulate" },
	},
	returns = "timer",
	valuetype = "mwseTimer",
}