return {
	type = "function",
	description = [[Gets per-pixel lighting parameters for a specific weather. See [`mge.setWeatherPPLLight()`](https://mwse.github.io/MWSE/apis/mge/#mgesetweatherppllight).]],
	arguments = {
		{ name = "weatherID", type = "number", description = "Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table." },
	},
	returns = {{ name = "parameters", type = "table", description = "An array-style table with `sunMultiplier` and `ambientMultiplier` parameters." }},
}