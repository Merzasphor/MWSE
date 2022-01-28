return {
	type = "function",
	description = [[Use [`tes3leveledCreature:insert()`](https://mwse.github.io/MWSE/types/tes3leveledCreature/#insert) instead. Wrapper for the `AddToLevCreature` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "list", type = "tes3leveledCreature|string", description = "Leveled creature list to add a creature to." },
			{ name = "creature", type = "tes3actor|string", description = "Creature to add to the list." },
			{ name = "level", type = "number", default = 0, description = "Minimum level for the creature to spawn." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
