return {
	type = "function",
	description = [[This function creates a dialogue message. The message can have three styles. The style `2` makes a selectable text. That way by calling this function multiple time you can create a selection of responses.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "text", type = "string", optional = true, default = "", description = "The text of the shown message." },
			{ name = "style", type = "number", optional = true, default = 0, description = "This argument controls the text color of the message. Value `0` makes the message text the same color as the text in the dialogue window. Value `1` makes the text white, and also print a newline after the message. Value `2` turns the message into a selectable text inside the dialogue window. Value `3` looks the same as `1` but there isn't a newline after each message. Value `4` is the same as value `1`. All the other values work as `0`." },
			{ name = "answerIndex", type = "number", optional = true, default = 0, description = "This number can be used later to identify which response was selected." },
		},
	}},
}
