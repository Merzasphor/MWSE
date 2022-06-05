return {
	type = "function",
	description = [[Logs a message to the console. Consider using `tes3ui.log` instead of this function if you do not need to make use of the `isCommand` parameter.]],
	arguments = {
		{ name = "text", type = "string" },
		{ name = "isCommand", type = "boolean", default = false, description = "Passing `true` will make the text in the console selectable by using up arrow key. If it is a valid command, then pressing enter will call it." },
	},
	examples = {
		["isCommandUse"] = {
			title = "This example describes how this function behaves with isCommand = true."
		}
	}
}
