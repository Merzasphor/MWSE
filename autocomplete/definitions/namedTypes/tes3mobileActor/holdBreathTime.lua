return {
	type = "value",
	description = "This is the time the actor can stay underwater without taking drowning damage, measured in seconds. It's starting value is `fHoldBreathTime`(GMST) seconds by default. Once the actor is underwater, this value is decreasing based on the time passed while underwater. The actor will start taking drowning damage once this time is below 0. During drowning this time will have more and more negative values based on the duration of the drowning. Changing this allows manipulating for how long the actor can stay underwater without drowning. Note that player's Breath HUD element won't show values larger than `fHoldBreathTime`.",
	valuetype = "number",
}