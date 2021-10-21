return {
	type = "function",
	description = [[Determines if the player has access to a given spell.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "Who to check the spell list of. To check an actor without specifying any particular reference, use `actor` instead." },
			{ name = "actor", type = "tes3actor|string", description = "Who to check the spell list of. Providing a base actor can be done before a save has been loaded, but may not correctly update effects for instanced versions of that actor in an active save." },
			{ name = "spell", type = "tes3spell|string", description = "The spell to check." },
		},
	}},
	returns = {
		{ name = "hasSpell", type = "boolean", description = "True if the spell exists in the actor's spell list, race spell list, or birthsign spell list." },
	}
}