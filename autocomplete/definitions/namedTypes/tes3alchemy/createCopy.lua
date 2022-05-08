return {
	type = "method",
	description = [[Creates a copy of this object.]],
	arguments = { {
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "string", optional = true, description = "The new object's ID. If one is not provided, a randomly generated one will be used." },
			{ name = "addToObjectList", type = "boolean", default = true, description = "If true, the object will be added to the data handler. If this is false, the new object may not have a randomly generated ID. Do not use this without knowing the implications." },
			{ name = "sourceless", type = "boolean", default = false, description = "If true, the object will be made sourceless, and will not be serialized to the save game. If the object is copied outside of a save game, the object will **always** be sourceless." },
		},
	} },
	returns = {
		{ name = "newObject", type = "tes3alchemy" },
	}
}
