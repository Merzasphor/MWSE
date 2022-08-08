return {
	type = "function",
	description = [[Creates a new fader, and adds it to the fader system.]],
	arguments = {
		{ name = "distance", type = "number", optional = true, description = "If no distance is provided, a distance will be calculated based on current amount of faders, `tes3.worldController.projectionDistance` and crosshair node's `translation.y`." },
		{ name = "unknownBool", type = "boolean", optional = true, default = true },
	},
	returns = {{ name = "fader", type = "tes3fader" }},
}