return {
	type = "method",
	description = [[Checks to see if a skill is ready to be leveled up, and performs any levelup logic.]],
	arguments = {
		{ name = "skill", type = "integer", description = "The skill index to check for leveling. Maps to values from [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) table." },
	},
}