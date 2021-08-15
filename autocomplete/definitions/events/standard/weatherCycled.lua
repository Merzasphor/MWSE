return {
	type = "event",
	description = [[The **weatherCycled** event occurs when region weathers are randomized. This occurs at an interval set by the ini option “Hours Between Weather Changes”. Regions may select the same weather as before, and there will be no transition in this case.]],
	related = { "weatherCycled", "weatherTransitionFinished", "weatherChangedImmediate", "weatherTransitionStarted", "weatherChangedImmediate" },
}