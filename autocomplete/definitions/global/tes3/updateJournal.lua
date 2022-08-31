return {
	type = "function",
	description = [[Updates the journal index in a way similar to the mwscript function Journal.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "tes3dialogue|string" },
			{ name = "index", type = "number" },
			{ name = "showMessage", type = "boolean", optional = true, default = false, description = "If set, a message may be shown to the player." },
		},
	}},
	returns = "wasSet",
	valuetype = "boolean",
}