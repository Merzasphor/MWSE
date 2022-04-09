return {
	type = "function",
	description = [[Sets distant land fog parameters for a specific weather. `fogDistMultiplier` is multiplied by the "Above water fog" distance to get the fog distance for that weather. It has a range of [0, 2]. `fogOffsetPercent` is the percentage of fog applied at zero distance from the camera. It has a range of [0, 90].

Note: "Above water fog" is a setting specific to MGE XE. It can be found on the Distant Land page, under Fog category.]],
	arguments = {
		{ name = "weatherID", type = "number", description = "Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table." },
		{ name = "fogDistMultiplier", type = "number" },
		{ name = "fogOffsetPercent", type = "number" }
	},
	returns = {{ name = "result", type = "number" }},
}