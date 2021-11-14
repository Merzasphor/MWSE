return {
	type = "function",
	description = [[Configures MWSE to no longer execute a lua function instead when a script would run. This undoes the work of `mwse.overrideScript`.]],
	arguments = {
		{ name = "scriptId", type = "string" },
	},
	returns = "boolean",
}