return {
	type = "event",
	description = [[The **weatherTransitionFinished** event occurs when the currently simulated weather finished transitioning to a new weather.

Weather will continue transitioning in interiors, and may finish while in an interior. The transition may be interrupted at any time by the `weatherChangedImmediate` event, and this finish event will not be triggered.]],
	related = { "weatherCycled", "weatherTransitionFinished", "weatherChangedImmediate", "weatherTransitionStarted", "weatherChangedImmediate" },
	eventData = {
		to = {
			type = "tes3weather",
			description = "The weather object that will be transitioned to.",
		},
	},
}