return {
	type = "function",
	description = [[Plays a given animation group. Optional flags can be used to define how the group starts.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference|string", description = "The reference that will play the animation." },
			{ name = "group", type = "number", default = 0, description = "The group id -- a value from 0 to 149. Maps to tes3.animationGroup.* constants." },
			{ name = "startFlag", type = "number", default = 0, description = "A flag for starting the group with, matching tes3.animationStartFlag.* constants." },
			{ name = "loopCount", type = "number", optional = true, description = "If provided, the animation will loop a given number of times." },
			{ name = "file", type = "string", optional = true, description = "If provided, the specified animation file will be loaded. The animation target skeleton must match the skeleton of the actor to work. Animation groups present in the file will replace the actor's animation groups. This replacement will only persist until the mobile actor is unloaded." },
		},
	}},
}
