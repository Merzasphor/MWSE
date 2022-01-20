return {
	type = "method",
	description = [[Changes the current weather for the region to the provided weather-type parameter.]],
	arguments = {
		{ name = "weatherId", type = "number", description = "Maps to values in [`tes3.weather`](https://mwse.github.io/MWSE/references/weather-types/) namespace." },
	},
}