return {
	type = "function",
	description = [[Creates a timer.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "type", type = "number", optional = true, description = "Defaults to timer.simulate." },
			{ name = "duration", type = "number", description = "Duration of the timer. The method of time passing depends on the timer type." },
			{ name = "callback", type = "function", description = "The callback function that will execute when the timer expires." },
			{ name = "iterations", type = "number", default = 1, description = "The number of iterations to run." },
		}
	}},
	returns = "timer",
	valuetype = "mwseTimer",
	examples = {
		["ShowCountdownMessage"] = {
			title = "Show a Countdown Message",
			description = "In this example, whenever the player activates an item they will be shown a 10 second countdown. Because it is a simulation timer, it will not tick down while the menu is open, nor is it sensitive to the game timescale/clock.",
		},
	},
}