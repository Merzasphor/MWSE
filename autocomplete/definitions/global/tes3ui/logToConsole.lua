return {
	type = "function",
	description = [[Logs a message to the console.]],
	arguments = {
		{ name = "text", type = "string" },
		{ name = "isCommand", type = "boolean", default = false },
	},
	examples = {
		["logPlayerSkillTypes"] = {
			title = "Print the type of each of the player's skills to the console"
		}
	}
}
