return {
	type = "event",
	description = [[The **combatStopped** event occurs after an actor has left combat. This event is preceded by the [combatStop](https://mwse.github.io/MWSE/events/combatStop) event.]],
	related = { "combatStart", "combatStarted", "combatStop", "combatStopped" },
	eventData = {
		["actor"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor who has left combat.",
		},
	},
}