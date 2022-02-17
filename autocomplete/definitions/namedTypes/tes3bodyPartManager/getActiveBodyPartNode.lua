return {
	type = "method",
	description = [[The method fetches the NiNode-derived object for the loaded mesh of an active body part at a given layer and position.]],
	arguments = {
		{ name = "layer", type = "number", description = "A value from [`tes3.activeBodyPartLayer`](https://mwse.github.io/MWSE/references/active-body-part-layers/) namespace." },
		{ name = "index", type = "number", description = "A value from [`tes3.activeBodyPart`](https://mwse.github.io/MWSE/references/active-body-parts/) namespace." },
	},
	valuetype = "niNode",
}
