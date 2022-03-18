return {
	type = "function",
	description = [[Logs a message to `MWSE.log` file. The output format is `[path] "msg" = msg`, where the `path` is the path and line at which the function was called.]],
	arguments = {
		{ name = "value", type = "string", description = "The message to log." },
	},
	returns = {{ name = "value", type = "string" }},
}