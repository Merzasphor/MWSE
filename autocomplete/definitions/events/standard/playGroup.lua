return {
	type = "event",
	description = "This event is triggered when an animation is about to be played.",
	eventData = {
		["animationData"] = {
			type = "tes3animationData",
			readOnly = true,
			description = "The related animation data.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The actor that is about to play the animation.",
		},
		["group"] = {
			type = "number",
			description = "The animation group about to be played. Maps to values in [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) namespace.",
		},
		["index"] = {
			type = "number",
			readOnly = true,
			description = "The index of the body section the animation will be played on. Maps to values in [`tes3.animationBodySection`](https://mwse.github.io/MWSE/references/animation-body-sections/) namespace.",
		},
		["flags"] = {
			type = "number",
			description = "Maps to values in [`tes3.animationStartFlag`](https://mwse.github.io/MWSE/references/animation-start-flags/) namespace.",
		},
		["loopCount"] = {
			type = "number",
			description = "The number of times the animation is going to be played. Infinite looping is marked by `-1`, while `0` means the animation will be played only once (no looping).",
		},
	},
	filter = "reference",
	blockable = true,
}
