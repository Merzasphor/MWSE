return {
	type = "function",
	description = "Creates",
	arguments = {
		{ name = "string", type = "string", description = "The message to display. If it supports formatting, additional arguments are used." },
		{ name = "formatValues", type = "variadic", description = "Optional values to feed to formatting found in the first parameter." },
	},
	returns = {
		{ name = "menu", type = "tes3uiElement", description = "The notify menu created." },
	}
}
