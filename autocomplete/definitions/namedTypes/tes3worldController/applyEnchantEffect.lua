return {
	type = "function",
	description = [[This function applies an enchantment's effects to a scene node.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "node", type = "niNode", description = "A scene node to which to apply the enchantment's effects." },
			{ name = "enchantment", type = "tes3enchantment", description = "The enchantment's effects to apply." },
		},
	}},
	valuetype = "boolean",
}