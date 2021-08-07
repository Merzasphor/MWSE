return {
	type = "function",
	description = [[Creates a new alchemy item, which will be stored as part of the current saved game. If there is already an alchemy item with matching effects, name, weight, value, and script, that will be returned instead of creating a new item.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "string", description = "The new object's ID. Must be unique." },
			{ name = "name", type = "string", default = "\"Potion\"", description = "The new item's name." },
			{ name = "script", type = "tes3script", optional = true, description = "A script to attach to the object." },
			{ name = "mesh", type = "string", default = "\"m\\Misc_Potion_Bargain_01.nif\"", description = "The mesh to use for the object." },
			{ name = "icon", type = "string", default = "\"m\\Tx_potion_bargain_01.nif\"", description = "The icon to use for the object." },
			{ name = "objectFlags", type = "number", default = 8, description = "The object flags initially set. Force set as modified." },
			{ name = "weight", type = "number", default = 0, description = "The new item's weight." },
			{ name = "value", type = "number", default = 0, description = "The new item's value." },
			{ name = "flags", type = "number", default = 0, description = "The new alchemy item's flags." },
			{ name = "effects", type = "table", description = "A table of effects described, providing values for id, skill, attribute, range, radius, duration, min, and/or max." },
		},
	}},
}