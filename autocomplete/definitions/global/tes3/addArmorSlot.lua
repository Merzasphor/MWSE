return {
	type = "function",
	description = [[Registers a new slot to be used..]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "slot", type = "number", description = "A number greater than 10 to configure a slot for." },
			{ name = "name", type = "string" },
			{ name = "weight", type = "number", description = "A stand-in for the armor base weight value, typically controlled by a GMST (e.g. iHelmWeight)." },
		},
	}},
	returns = "wasAdded",
	valuetype = "boolean",
}