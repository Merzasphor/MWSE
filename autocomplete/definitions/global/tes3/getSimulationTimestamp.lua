return {
	type = "function",
	description = [[Returns a UNIX-style timestamp based on in-world simulation time since the start of the era, in hours.]],
	arguments = {
		{ name = "highPrecision", optional = true, default = true, type = "boolean", description = "If `false` is passed returns the value of the simulation time variable used by the game engine. Calculates the timestamp from the current year, month and game hour global variables otherwise." }
	},
	returns = { name = "timestamp", type = "number" }
}