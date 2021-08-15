return {
	type = "event",
	description = [[One of the movement events, **calcFlySpeed** is used when calculating movement speeds when levitating or otherwise flying.

The movement event flow is described below:

- Flying: **calcFlySpeed** -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)]],
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
			description = "The type of movement that was calculated. This is always 5 for this event.",
		},
	},
}