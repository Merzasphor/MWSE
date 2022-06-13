return {
	type = "method",
	description = [[For this faction, this function finds the worst reaction for another faction that the player has joined. It returns that reaction and its associated faction, or `nil` for both values if the no relationship is applicable.]],
	returns = {
		{ name = "reaction", type = "number|nil", description = "The reaction, if any, that is worst for the player." },
		{ name = "faction", type = "tes3faction|nil", description = "The faction association, if any, that is worst for the player." },
	},
}
