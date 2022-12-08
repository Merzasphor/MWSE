return {
	type = "function",
	description = [[Creates a new Timer Controller. Its initial clock is zero, unless a start time is provided.]],
	arguments = {
		{ name = "startTime", type = "number", optional = true, defualt = 0 },
	},
	valuetype = "mwseTimerController"
}