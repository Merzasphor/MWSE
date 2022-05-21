return {
	type = "function",
	description = [[Use [`tes3.addTopic()`](https://mwse.github.io/MWSE/apis/tes3/#tes3addtopic) instead. Wrapper for the `AddTopic` mwscript function.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "topic", type = "tes3dialogue|string" },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
