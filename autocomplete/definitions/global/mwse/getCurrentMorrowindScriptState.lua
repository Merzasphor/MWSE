return {
	type = "function",
	description = [[This function returns information on the current mwscript execution state.]],
	returns = {
		{ name = "script", type = "tes3script|nil", description = "The currently executing mwscript script, or nil if none is presently being executed." },
		{ name = "reference", type = "tes3reference|nil", description = "The currently executing mwscript script's associated reference. This will be nil for global scripts, or nil if no script is presently being executed." },
	},
}
