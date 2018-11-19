return {
	type = "function",
	description = [[Plays a music track.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "path", type = "string", description = "Path to the music file, relative to Data Files/music/." },
			{ name = "situation", type = "number", default = "tes3.musicSituation.uninterruptible", description = [[Determines what kind of gameplay situation the music should stay active for.]] },
			{ name = "crossfade", type = "number", default = "1.0", description = "The duration in seconds of the crossfade from the old to the new track. The default is 1.0." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
