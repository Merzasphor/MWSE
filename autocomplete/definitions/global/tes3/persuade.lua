return {
	type = "function",
	description = [[Attempts a persuasion attempt on an actor, potentially adjusting their disposition. Returns true if the attempt was a success.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "actor", type = "tes3mobileActor|tes3reference|string", description = "The actor to try to persuade.", },
			{ name = "index", type = "number", optional = true, description = "If an index is provided, 0-indexed with the following results: admire, intimidate, taunt, bribe (10), bribe (100), bribe (1000).", },
			{ name = "modifier", type = "number", optional = true, description = "If no index is provided, this is the direct modifier to try. The higher the modifer the higher the chance of a successful persuation, and higher disposition change.", },
		},
	}},
	returns = { name = "success", type = "boolean" }
}