return {
	type = "method",
	description = [[This method plays an animation group on the provided body section of related actor, invoking `playGroup` event.]],
	arguments = {
		{ name = "animationGroup", type = "number", description = "The animation group to play. A value from [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) namespace." },
		{ name = "triIndex", type = "number", description = "The body section on which to play the animation. A value from [`tes3.animationBodySection`](https://mwse.github.io/MWSE/references/animation-body-sections/) namespace." },
		{ name = "startFlag", type = "number", description = "A flag for starting the group with, using [`tes3.animationStartFlag`](https://mwse.github.io/MWSE/references/animation-start-flags/) constants." },
		{ name = "loopCount", type = "number", description = "If provided, the animation will repeat its loop section a given number of times. To make an animation play through once, set loopCount = 0, while -1 is used for infinite looping." }
	}
}
