return {
	type = "function",
	description = [[Causes a target actor to play a voiceover.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "actor", type = "tes3mobileActor|tes3reference|string", description = "The actor to play a voiceover." },
			{ name = "voiceover", type = "number", description = "Maps to [`tes3.voiceover`](https://mwse.github.io/MWSE/references/voiceovers/) constants." },
		},
	}},
	returns = "played",
	valuetype = "boolean",
}