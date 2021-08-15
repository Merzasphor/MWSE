return {
	type = "event",
	description = [[This event is called when an actor’s movement speed is calculated. The event allows modification of this value, to dehardcode actor movement speeds. Invoked after all other movement speed events are finished.

The movement event flow is described below:

- Walking: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> **calcMoveSpeed**
- Running: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> [calcRunSpeed](https://mwse.github.io/MWSE/events/calcRunSpeed) -> **calcMoveSpeed**
- Swimming: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> [calcSwimSpeed](https://mwse.github.io/MWSE/events/calcSwimSpeed) -> **calcMoveSpeed**
- Swimming (while running): [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> [calcSwimSpeed](https://mwse.github.io/MWSE/events/calcSwimSpeed) -> [calcSwimRunSpeed](https://mwse.github.io/MWSE/events/calcSwimRunSpeed) -> **calcMoveSpeed**
- Flying: [calcFlySpeed](https://mwse.github.io/MWSE/events/calcFlySpeed) -> **calcMoveSpeed**]],
	related = { "calcMoveSpeed", "calcWalkSpeed", "calcRunSpeed", "calcFlySpeed", "calcSwimSpeed", "calcSwimRunSpeed" },
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor whose speed is being calculated.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "mobile’s related reference.",
		},
		["speed"] = {
			type = "number",
			description = "The previous speed calculated, starting with the base engine values.",
		},
		["type"] = {
			type = "number",
			readOnly = true,
			description = "The type of movement that was calculated. This is always 0 for this event.",
		},
	},
	examples = {
		["FastMovement"] = {
			title = "20% Faster Player Movement",
		},
	},
	links = {
        ["calcWalkSpeed"] = "lua/event/calcWalkSpeed",
        ["calcRunSpeed"] = "lua/event/calcRunSpeed",
        ["calcSwimSpeed"] = "lua/event/calcSwimSpeed",
        ["calcSwimRunSpeed"] = "lua/event/calcSwimRunSpeed",
        ["calcFlySpeed"] = "lua/event/calcFlySpeed",
    },
}