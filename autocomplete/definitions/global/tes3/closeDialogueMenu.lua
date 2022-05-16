return {
	type = "function",
	description = [[This function closes the dialogue menu.]],
		arguments = {{
			name = "params",
			type = "table",
			tableParams = {
				{ name = "force", type = "boolean", default = true, description = "Normally, the menu can't be closed in certain circumstances, such as when the player is making a dialogue choice. If true, these usual restrictions will be ignored." },
			},
		}},
	returns = {
		{ name = "wasClosed", type = "boolean", description = "If true, the menu was previously open, and is now closed." },
	}
}
