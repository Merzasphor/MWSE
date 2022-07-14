return {
	type = "function",
	description = [[Gets the spells of an actor. This can be filtered by `spellType` and set to include or exclude actor, racial and birthsign spells.]],
	arguments = {
		{
			name = "params",
			type = "table",
			tableParams = {
				{
					name = "target",
					type = "tes3reference|tes3mobileActor|tes3actor",
					description = "The actor to get the spells of. Must be able to cast spells."
				},
				{
					name = "spellType",
					type = "number",
					optional = true,
					default = "-1",
					description = "The spell type to filter for. Only spells with this spell type will be returned. A value of `-1` will return spells of all types. Maps to values in the [`tes3.spellType`](https://mwse.github.io/MWSE/references/spell-types/) table."
				},
				{
					name = "getActorSpells",
					type = "boolean",
					optional = true,
					default = "true",
					description = "If `true`, the spells of the actor itself will be included in the result. This includes every spell except racial and birthsign spells."
				},
				{
					name = "getRaceSpells",
					type = "boolean",
					optional = true,
					default = "true",
					description = "If `true`, the spells of the actor's race will be included in the result."
				},
				{
					name = "getBirthsignSpells",
					type = "boolean",
					optional = true,
					default = "true",
					description = "If `true`, the spells of the actor's birthsign will be included in the result."
				},
			}
		}
	},
	valuetype = "tes3spell[]",
}
