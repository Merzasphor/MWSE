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
				{ name = "showInDialog", type = "boolean", optional = true, default = "true", description = "Specifying showInDialog = false forces the toast-style message, which is not shown in the dialog menu." },
				{ name = "duration", type = "number", description = "Overrides how long the toast-style message remains visible.", optional = true },
			},
		},
		{ name = "formatAdditions", type = "variadic", optional = true, description = "Only used if messageOrParams is a string." },
	},
	returns = {
		{ name = "element", type = "tes3uiElement|nil", description = "The UI menu created for the notification, if any." }
	}
}
