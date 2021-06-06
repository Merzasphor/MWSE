return {
	type = "function",
	description = [[Sets player's kill count as a Werewolf.]],
	arguments = {
		name = "params",
		type = "table",
		tableParams = {
			{ name = "count", type = "number", description = "Number of kills." },
		},
	},
}
