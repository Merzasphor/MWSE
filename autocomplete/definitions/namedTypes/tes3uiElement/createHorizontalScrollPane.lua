return {
	type = "method",
	description = [[Creates a horizontally scrolling pane.

Scroll pane specific properties can be accessed through the `widget` property. The widget type for scroll panes is [`tes3uiScrollPane`](https://mwse.github.io/MWSE/types/tes3uiScrollPane/).]],
	arguments = {
		{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
	},
	valuetype = "tes3uiElement",
}