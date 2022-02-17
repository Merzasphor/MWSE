return {
	type = "method",
	description = [[The method sets a new body part for a given object.]],
	arguments = {
		{ name = "object", type = "tes3physicalObject", description = "An object whose body part to set." },
		{ name = "index", type = "number", description = "A value from [`tes3.activeBodyPart`](https://mwse.github.io/MWSE/references/active-body-parts/) namespace." },
		{ name = "bodyPartId", type = "string", description = "The unique ID of the `tes3bodyPart` object to set as a new body part for given object." },
		{ name = "isFirstPerson", type = "boolean", optional = true, default = "false", description = "A flag which controls whether the body part is used in first person." },
	},
}
