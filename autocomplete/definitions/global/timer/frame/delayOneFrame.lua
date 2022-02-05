return {
	type = "function",
	description = [[Creates a timer that will finish the next frame.]],
	arguments = {
		{ name = "callback", type = "function", description = "The callback function that will execute when the timer expires." },
		},
	returns = "timer",
	valuetype = "mwseTimer",
}
