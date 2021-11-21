return {
	type = "method",
	description = [[The method sets a new body part for a given object.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "object", type = "tes3physicalObject", description = "A object whose body part to set." },
			{ name = "index", type = "number", description = "A value in tes3.activeBodyPart.* constants." },
			{ name = "bodyPart", type = "tes3bodyPart", description = "The tes3bodyPart object to set as a new body part for given object." },
			{ name = "isFirstPerson", type = "boolean", optional = true, default = "false", description = "A flag which controls whether the body part is used in first person." },
		},
	}},
}