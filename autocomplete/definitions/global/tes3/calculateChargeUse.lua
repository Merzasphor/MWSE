return {
	type = "function",
	description = [[Calculates the actual charge use of an enchantment by a mobile actor, after skills are applied. Invokes the enchantChargeUse event to account for modded charge usage. Takes into account the MCP charge use rebalance patch, if activated.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "object", type = "tes3enchantment", description = "The enchantment to check." },
			{ name = "mobile", type = "tes3mobileActor", description = "The mobile actor that would be casting the enchantment." },
		},
	}},
	returns = {
		{ name = "chargeUse", type = "number", description = "Actual charge use." },
	},
}
