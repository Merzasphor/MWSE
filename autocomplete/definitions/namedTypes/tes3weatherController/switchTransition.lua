return {
	type = "method",
	description = [[Transitions the weather to the provided weather parameter based on the weather controller settings.]],
	arguments = {
		{ name = "weatherId", type = "number", description = "Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table." },
	},
}