return {
	type = "function",
	description = [[Gets distant land fog parameters for a specific weather. See [`mge.setWeatherDLFog()`](https://mwse.github.io/MWSE/apis/mge/#mgesetweatherdlfog).]],
	arguments = {
		{ name = "weatherID", type = "number", description = "Maps to values in [`tes3.weather`](https://mwse.github.io/MWSE/references/weather-types/) enumeration." },
	},
	returns = {{ name = "parameters", type = "table", description = "An array-style table with `fogDistMultiplier` and `fogOffsetPercent` parameters." }},

}