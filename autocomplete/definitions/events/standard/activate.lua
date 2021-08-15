return {
	type = "event",
	description = [[This event is invoked whenever something is activated, typically by the player. Activation is usually done with the associated activate/use key, but may also be forced by scripts.

Non-player actors may also activate objects, such as when opening doors, or via MWSE functions like [`tes3.activate()`](https://mwse.github.io/MWSE/apis/tes3/#tes3activate).

Some examples of when the activate event fires includes:

- When a door is used.
- When an item is picked up.
- When someone attempts to open a container.]],
	eventData = {
		["activator"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The actor attempting to trigger the event.",
		},
		["target"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The reference that is being activated.",
		},
	},
	filter = "target",
	blockable = true,
	examples = {
		["ShowActivationTarget"] = {
			title = "Show a message for what the player is activating",
		},
		["PreventActivatingNPCs"] = {
			title = "Prevent the player from activating NPCs",
		},
	},
	links = {
		["xActivate"] = "mwscript/functions/actor/xActivate",
	},
}