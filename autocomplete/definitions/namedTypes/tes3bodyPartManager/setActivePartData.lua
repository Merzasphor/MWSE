return {
	type = "method",
	description = [[The method sets a niNode derived object as active body part at a given layer and position.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "layer", type = "number", description = "A value in tes3.activeBodyPartLayer.* constants." },
			{ name = "index", type = "number", description = "A value in tes3.activeBodyPart.* constants." },
			{ name = "overwriteData", type = "boolean", optional = true, default = true, description = "A flag which controls whether the current data should be overwritten." },
			{ name = "node", type = "niNode", optional = true, default = "nil", description = "" },
		},
	}},
}