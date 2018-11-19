return {
	type = "function",
	description = [[Displays a message box. This may be a simple toast-style message, or a box with choice buttons.]],
	arguments = {
		{
			name = "messageOrParams",
			type = "string|table",
			tableParams = {
				{ name = "message", type = "string" },
				{ name = "buttons", type = "table", description = "An array of strings to use for buttons.", optional = true },
				{ name = "callback", type = "function" },
			},
		},
		{ name = "formatAdditions", type = "variadic", optional = true, description = "Only used if messageOrParams is a string." },
	},
	returns = "soundIsPlaying",
	valuetype = "boolean",
}
