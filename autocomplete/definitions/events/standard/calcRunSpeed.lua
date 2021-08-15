return {
	type = "event",
	description = [[One of the movement events, **calcRunSpeed** is used when calculating when the player is running, but not swimming or flying.

The movement event flow is described below:

- Running: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> **calcRunSpeed** -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)]],
	related = { "calcMoveSpeed", "calcWalkSpeed", "calcRunSpeed", "calcFlySpeed", "calcSwimSpeed", "calcSwimRunSpeed" },
	eventData = {
		mobile = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor whose speed is being calculated.",
		},
		reference = {
			type = "tes3reference",
			readOnly = true,
			description = "mobile’s related reference.",
		},
		speed = {
			type = "number",
			description = "The previous speed calculated, starting with the base engine values.",
		},
		type = {
			type = "number",
			readOnly = true,
			description = "The type of movement that was calculated. This is always 2 for this event.",
		},
	},
}