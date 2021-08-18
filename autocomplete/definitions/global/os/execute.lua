return {
	type = "function",
	description = [[Passes command to be executed by an operating system shell. To open a program to run in the background and monitor its output, use `os.createProcess`.]],
	arguments = {
		{ name = "command", type = "string", description = "The command to run." },
	},
	returns = {
		{ name = "exitCode", type = "number", description = "The exit code of the program." },
	},
}