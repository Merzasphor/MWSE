return {
	type = "method",
	description = "This function plays an animation for an effect from the `tes3magicSourceInstance` object.",
	arguments = {
		{
			name = "params",
			type = "table",
			tableParams = {
				{ name = "effectIndex", type = "number", description = "The index in the effect whose visual will be played, a number in range [0, 7]." },
				{ name = "position", type = "tes3vector3|table", description = "A table or a `tes3vector3` holding `x`, `y` and `z` coordinates at which the visual effect will be played." },
				{ name = "visual", type = "tes3physicalObject|string", description = "The visual effect to be played." },
				{ name = "scale", type = "number", optional = true, default = 1, description = "The scale of the effect. Only applies to effects that are designed to be scaled." },
				{ name = "reference", type = "tes3reference|string", description = "A reference on which the visual effect will be played." },
			},
		}
	},
	examples = {
		["soulTrapEffectOnVampireKill"] = {
			title = "Plays the soul trap effect if the player kills a target that is affected by vampirism.",
		},
	},
}
