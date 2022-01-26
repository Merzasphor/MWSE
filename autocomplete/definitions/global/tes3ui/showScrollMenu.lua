return {
	type = "function",
	description = [[Displays the scroll menu with arbitrary text. It needs to follow book text conventions as in the Construction Set. In essence, it uses HTML syntax. Important: every book needs to end with a `<BR>` statement to be displayed properly. See [`bookGetText`](https://mwse.github.io/MWSE/events/bookGetText/#examples) for an example of properly formatted scroll text.]],
	arguments = {
		{ name = "text", type = "string" },
	},
}
