return {
	type = "function",
	description = [[Sets a statistic on a given actor. This should be used instead of manually setting values on the game structures, to ensure that events and GUI elements are properly handled. Either skill, attribute, or name must be provided.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "attribute", type = "number", optional = true, description = "The attribute to set." },
			{ name = "base", type = "number", optional = true, description = "If set, the base value will be set." },
			{ name = "current", type = "number", optional = true, description = "If set, the current value will be set." },
			{ name = "limit", type = "boolean", optional = true, default = false, description = "If set, the attribute won't rise above 100 or fall below 0." },
			{ name = "name", type = "string", optional = true, description = "A generic name of an attribute to set." },
			{ name = "reference", type = "tes3mobileActor|tes3reference|string" },
			{ name = "skill", type = "number", optional = true, description = "The skill to set." },
			{ name = "value", type = "number", optional = true, description = "If set, both the base and current value will be set." },
		},
	}},
}