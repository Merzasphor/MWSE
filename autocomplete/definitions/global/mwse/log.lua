return {
	type = "function",
	description = [[This function writes information to the MWSELog.txt file in the user's installation directory.

The message accepts formatting and additional parameters matching string.format's usage.]],
	arguments = {
		{ name = "message", type = "string" },
		{ type = "variadic", optional = true }
	},
	returns = "nil",
}