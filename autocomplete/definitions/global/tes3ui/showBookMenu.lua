return {
	type = "function",
	description = [[Displays the book menu with arbitrary text. Paging is automatically handled. It needs to follow book text conventions as in the Construction Set. In essence, it uses HTML syntax. Important: every book needs to end with a `<BR>` statement to be displayed properly. See [`bookGetText`](https://mwse.github.io/MWSE/events/bookGetText/#examples) for an example of properly formatted book text.]],
	arguments = {
		{ name = "text", type = "string" },
	},
}
