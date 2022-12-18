return {
	type = "method",
	description = [[Exercises a skill, providing experience in it. Invokes `exerciseSkill` event.]],
	arguments = {
		{ name = "skill", type = "integer", description = "The skill index to give experience to. Maps to values from [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) table." },
		{ name = "progress", type = "number", description = "The amount of experience to grant." },
	},
}