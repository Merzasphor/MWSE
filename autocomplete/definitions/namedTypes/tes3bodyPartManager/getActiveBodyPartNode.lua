return {
	type = "method",
	description = [[The method fetches the NiNode-derived object for the loaded mesh of an active body part at a given layer and position.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "layer", type = "number", description = "A value in tes3.activeBodyPartLayer.* constants." },
			{ name = "index", type = "number", description = "A value in tes3.activeBodyPart.* constants." },
		},
	}},
	valuetype = "niNode",
}