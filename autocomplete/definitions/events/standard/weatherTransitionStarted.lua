return {
	type = "event",
	description = [[The **weatherTransitionStarted** event occurs when the currently simulated weather has started to gradually transition to a new weather. This can occur when moving between regions, or when the weather cycles.

Weather will not start transitioning in interiors, but will continue transitioning, and may finish while in an interior. The transition may be interrupted at any time by the [weatherChangedImmediate](https://mwse.github.io/MWSE/events/weatherChangedImmediate) event, and the [weatherTransitionFinished](https://mwse.github.io/MWSE/events/weatherTransitionFinished) event will not occur.]],
	related = { "weatherCycled", "weatherTransitionFinished", "weatherChangedImmediate", "weatherTransitionStarted", "weatherChangedImmediate" },
	eventData = {
		from = {
			type = "tes3weather",
			readOnly = true,
			description = "The weather object that is the current weather.",
		},
		to = {
			type = "tes3weather",
			description = "The weather object that will be transitioned to.",
		},
	},
}