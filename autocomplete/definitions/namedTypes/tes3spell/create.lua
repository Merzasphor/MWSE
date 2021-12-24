return {
	type = "function",
	deprecated = true,
	description = [[Use [`tes3.createObject()`](https://mwse.github.io/MWSE/apis/tes3/#tes3createobject) instead. This function created a new spell object, which will be stored as part of the current saved game.]],
	arguments = {
		{ name = "id", type = "string", optional = false, description = "The new object's ID. Must be unique." },
		{ name = "name", type = "string", optional = true, description = "The new object's name." },
	}
}
