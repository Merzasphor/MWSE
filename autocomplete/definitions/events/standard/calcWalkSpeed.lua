return {
	type = "event",
	description = [[One of the movement events, **calcWalkSpeed** is used when calculating the base walk speed. Nearly every other movement speed event starts with this, with the exception of [calcFlySpeed](https://mwse.github.io/MWSE/events/calcFlySpeed).

The movement event flow is described below:

- Walking: **calcWalkSpeed** -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)
- Running: **calcWalkSpeed** -> [calcRunSpeed](https://mwse.github.io/MWSE/events/calcRunSpeed) -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)
- Swimming: **calcWalkSpeed** -> [calcSwimSpeed](https://mwse.github.io/MWSE/events/calcSwimSpeed) -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)
- Swimming (while running): **calcWalkSpeed** -> [calcSwimSpeed](https://mwse.github.io/MWSE/events/calcSwimSpeed) -> [calcSwimRunSpeed](https://mwse.github.io/MWSE/events/calcSwimRunSpeed) -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)]],
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
			description = "The type of movement that was calculated. This is always 1 for this event.",
		},
	},
}