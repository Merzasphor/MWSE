return {
	type = "function",
	description = [[This function interrupts the current music to play the specified music track.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "path", type = "string", description = "Path to the music file, relative to Data Files/music/." },
			{ name = "situation", type = "number", default = "tes3.musicSituation.uninterruptible", description = [[Determines what kind of gameplay situation the music should stay active for. Explore music plays during non-combat, and ends when combat starts. Combat music starts during combat, and ends when combat ends. Uninterruptible music always plays, ending only when the track does. This value maps to [`tes3.musicSituation`](https://mwse.github.io/MWSE/references/music-situations/) constants.]] },
			{ name = "crossfade", type = "number", default = "1.0", description = "The duration in seconds of the crossfade from the old to the new track. The default is 1.0." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
