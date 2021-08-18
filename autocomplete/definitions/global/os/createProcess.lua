return {
	type = "function",
	description = [[Passes command to be executed by an operating system. Unlike `os.execute`, this will not display a console prompt that interrupts the game and cannot run direct shell commands.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "command", type = "string", description = "The command to run." },
			{ name = "async", type = "boolean", default = "true", description = "If set to false, Morrowind will halt execution until the program finishes." },
		},
	}},
	returns = {
		{ name = "executor", type = "mwseLuaExecutor|nil", description = "If running with `async`, and if successful, this is a handle to the executor. This can be used to check if the program has finished running and to get the program's output." },
	},
}