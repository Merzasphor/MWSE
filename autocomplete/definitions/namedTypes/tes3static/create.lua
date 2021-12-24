return {
	type = "function",
	deprecated = true,
	description = [[Use [`tes3.createObject()`](https://mwse.github.io/MWSE/apis/tes3/#tes3createobject) instead. This function creates a new static object, which will be stored as part of the current saved game.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "string", optional = true, description = "The new object's ID. Must be unique if provided." },
			{ name = "mesh", type = "string", default = "", description = "The mesh to use for the object." },
			{ name = "objectFlags", type = "number", default = 0, description = "The object flags initially set. Force set as modified." }
		},
	}},
}
