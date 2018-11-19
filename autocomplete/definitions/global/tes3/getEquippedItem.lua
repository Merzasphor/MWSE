return {
	type = "function",
	description = [[Returns an actor's equipped item stack, provided a given filter]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "actor", type = "tes3reference|tes3mobileActor|tes3actor" },
			{ name = "enchanted", type = "boolean", optional = true, description = "If true, filters to enchanted items." },
			{ name = "objectType", type = "number", optional = true, description = "Maps to tes3.objectType constants. Used to filter equipment by type." },
			{ name = "slot", type = "number", optional = true, description = "Maps to tes3.armorSlot or tes3.clothingSlot. Used to filter equipment by slot." },
			{ name = "type", type = "number", optional = true, description = "Maps to tes3.weaponType. Used to filter equipment by type." },
		},
	}},
	returns = "stack",
	valuetype = "tes3equipmentStack",
}