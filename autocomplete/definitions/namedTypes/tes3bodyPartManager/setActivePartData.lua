return {
	type = "method",
	description = [[The method sets a niNode derived object as active body part at a given layer and position.]],
	arguments = {
		{ name = "layer", type = "number", description = "A value from [`tes3.activeBodyPartLayer`](https://mwse.github.io/MWSE/references/active-body-part-layers/) namespace." },
		{ name = "index", type = "number", description = "A value from [`tes3.activeBodyPart`](https://mwse.github.io/MWSE/references/active-body-parts/) namespace." },
		{ name = "overwriteData", type = "boolean", optional = true, default = true, description = "A flag which controls whether the current data should be overwritten." },
		{ name = "node", type = "niNode", optional = true, default = "nil", description = "" },
	},
}
