return {
	type = "function",
	description = [[Returns a sound generator by a given creature id and type.]],
	arguments = {
		{ name = "creatureId", type = "string" },
		{ name = "soundType", type = "number", description = "Maps to [`tes3.soundGenType`](https://mwse.github.io/MWSE/references/sound-generator-types/) constants." },
	},
	returns = "soundGenerator",
	valuetype = "tes3soundGenerator",
}