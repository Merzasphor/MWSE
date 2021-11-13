return {
	type = "function",
	description = [[Registers a named timer with a callback to persist between game sessions. Bear in mind that nothing in MWSE is sandboxed, so all the registered timers are in the global namespace. Consider prefixing your timer with mod name or something else to avoid name colligions. For instance, "iceCreamMod:myTimer".]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "name", type = "string", description = "Name of the registered timer." },
			{ name = "fn", type = "function", description = "A callback function for the timer." },
		}
	}},
	examples = {
		["dayLater"] = {
			title = "Show a Message After 1 Day",
			description = "The timer registered in the example is registered and persistent. That renders starting the timer on every loaded event unnecessary. Its state is saved, and it continues where it stopped after loading a save game.",
		},
	},
}