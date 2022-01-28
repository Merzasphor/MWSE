return {
	type = "function",
	description = [[Use [`tes3.createReference()`](https://mwse.github.io/MWSE/apis/tes3/#tes3createreference) instead. Wrapper for the `PlaceAtPC` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "object", type = "tes3object|string", description = "The object to place." },
			{ name = "count", type = "number", default = 1 },
			{ name = "distance", type = "number", default = 256 },
			{ name = "direction", type = "number", default = 1 },
		},
	}},
	returns = {{ name = "lastPlacedReference", type = "tes3reference" }},
}
