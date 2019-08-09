return {
	description = "One of the movement events, calcFlySpeed is used when calculating movement speeds when levitating or otherwise flying.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor whose speed is being calculated.",
		},
		["reference"] = {
			type = "tes3reference",
			readonly = true,
			description = "mobile’s related reference.",
		},
		["speed"] = {
			type = "number",
			description = "The previous speed calculated, starting with the base engine values.",
		},
		["type"] = {
			type = "number",
			readonly = true,
			description = "The type of movement that was calculated. This is always 5 for this event.",
		},
	},
	links = {
        ["calcMoveSpeed"] = "lua/event/calcMoveSpeed",
    },
}