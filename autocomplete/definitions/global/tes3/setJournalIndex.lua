return {
	type = "function",
	description = [[Sets the index of a given journal in a way similar to the mwscript function SetJournalIndex.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "tes3dialogue|string" },
			{ name = "index", type = "number" },
			{ name = "speaker", type = "tes3mobileActor|tes3reference|string" },
			{ name = "showMessage", type = "boolean", optional = true, default = false, description = "If set, a message may be shown to the player." },
		},
	}},
	returns = "wasSet",
	valuetype = "boolean",
}