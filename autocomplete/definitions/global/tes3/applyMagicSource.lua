return {
	type = "function",
	description = [[]],
	arguments = {
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string" },
			{ name = "source", type = "tes3object", optional = true, description = "A magic source to apply." },
			{ name = "effects", type = "table" , optional = true, description = "A table of effects to apply as a potion." },
			{ name = "createCopy", type = "boolean", optional = true, default = "false if no source is specified, true otherwise", description = "This parameter controls weather the function will return original magic source or a copy of the magic source." },
			{ name = "fromStack", type = "tes3equipmentStack", optional = true, description = "The piece of equipment this magic source is coming from." },
			{ name = "castChance", type = "number", optional = true, default = "This parameter allows overriding casting chance of the magic source." },
			{ name = "target", type = "tes3reference|tes3mobileActor|string", optional = true, description = "" },
			{ name = "bypassResistances", type = "boolean", optional = true, default = false, description = "Is this effect going to bypass magic resistance?" },
		},
	},
	returns = "instance",
	valuetype = "tes3magicSourceInstance",
}
