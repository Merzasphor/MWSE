return {
	type = "method",
	description = [[Returns the total progress needed to progress the skill to the next level. The actual amount of progress needed is the floor of the value returned by this function.]],
	arguments = {
		{ name = "skill", type = "integer", description = "The skill index to check. Maps to values from [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) table." },
	},
	returns = {
		{ name = "progressNeeded", type = "number" },
	}
}