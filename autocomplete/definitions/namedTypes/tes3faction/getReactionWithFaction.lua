return {
	type = "method",
	description = [[Returns a reaction value for another faction, or `nil` if no relationship exists between the two factions.]],
	arguments = {
		{ name = "faction", type = "tes3faction", description = "Another faction to get a reaction for." },
	},
	returns = {
		{ name = "reaction", type = "number|nil", description = "The reaction, if any, with the other faction." },
	},
}
