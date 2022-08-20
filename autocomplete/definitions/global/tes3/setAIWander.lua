return {
	type = "function",
	description = [[Configures a mobile actor to wander around a cell.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference", description = "This actor will wander around." },
			{ name = "idles", type = "number[]", description = "An array with 8 values that corresponds to the chance of playing each idle animation. For more info see [tes3aiPackageWander.idles](https://mwse.github.io/MWSE/types/tes3aiPackageWander/#idles)." },
			{ name = "range", type = "number", optional = true, default = 0 },
			{ name = "duration", type = "number", optional = true, default = 0, description = "How long the actor will be wandering around, in hours." },
			{ name = "time", type = "number", optional = true, default = 0 },
			{ name = "reset", type = "boolean", optional = true, default = true },
		},
	}},
}
