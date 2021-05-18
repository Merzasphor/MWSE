return {
	type = "function",
	description = [[Plays a given animation group. Optional flags can be used to define how the group starts.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference|string", description = "The reference that will play the animation." },
			{ name = "group", type = "number", default = 0, description = "The animation group id -- a value from 0 to 149. Maps to tes3.animationGroup.* constants." },
			{ name = "startFlag", type = "number", default = 1, description = "A flag for starting the group with, matching tes3.animationStartFlag.* constants. Defaults to tes3.animationStartFlag.immediate." },
			{ name = "loopCount", type = "number", optional = true, description = "If provided, the animation will repeat its loop section a given number of times. To make an animation play through once, set loopCount = 0. Defaults to infinite looping." },
			{ name = "boneGroup", type = "number", optional = true, description = "If provided, the animation will only play on the selected part of the actor, called a bone group. Use tes3.boneGroup.upperBody to only play the upper body part of the animation, or tes3.boneGroup.shieldArm to only play the shield arm part. Player control is still retained when this parameter is specified - movement is possible, while attacks and camera switching are deferred until the animation is over."},
			{ name = "mesh", type = "string", optional = true, description = "Deprecated. Please use tes3.loadAnimation (check its documentation) before calling playAnimation." },
		},
	}},
}
