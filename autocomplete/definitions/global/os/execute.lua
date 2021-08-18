return {
	type = "function",
	description = [[Passes command to be executed by an operating system shell. This will not display a console prompt that interrupts the game.]],
	arguments = {
		{ name = "command", type = "string", description = "The command to run." },
		{ name = "async", type = "boolean", default = "false", description = "If set to true, the program will be run in a separate thread. The second return value, `executor`, can be used to monitor its execution." },
	},
	returns = {
		{ name = "exitCode", type = "number", description = "The exit code of the program. If running with `async` and if successful, the exit code will be STILL_ACTIVE (259)." },
		{ name = "executor", type = "mwseLuaExecutor|nil", description = "If running with `async`, and if successful, this is a handle to the executor. This can be used to check if the program has finished running and to get the program's output." },
	},
}