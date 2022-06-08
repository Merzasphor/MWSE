return {
	type = "method",
	description = [[Creates a clickable text, colored as a link. When the link is clicked, a URL is opened in the player's browser. If the `confirm` property is set, a confirmation prompt is opened first.

Hyperlink-specific properties can be accessed through the `widget` property. The widget type for hyperlinks is [`tes3uiHyperlink`](https://mwse.github.io/MWSE/types/tes3uiHyperlink/).]],
	arguments = { {
		name = "params",
		type = "table",
		optional = true,
		tableParams = {
			{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
			{ name = "text", type = "string", description = "The text to add to the hyperlink." },
			{ name = "url", type = "string", description = "The URL to open when the text is clicked." },
			{ name = "confirm", type = "boolean", default = true, description = "If true, a confirmation prompt will be shown before any URL is opened." },
		},
	} },
	returns = {
		{ name = "element", type = "tes3uiElement" },
	}
}
