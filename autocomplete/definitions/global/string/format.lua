return {
	type = "function",
	description = "This function creates a string, given various values. The format follows the printf format, with the additional option of %q to automatically quote a string.",
	arguments = {
		{ name = "format", type = "string", description = "The format string to use for the output." },
		{ type = "values", optional = true, description = "Values to format into the given string." }
	},
	valuetype = "string",
}