return {
	type = "method",
	description = [[Creates a text label. It defaults to displaying all text on a single line. To get a multi-line label, set `wrap_text` to `true`. The element is created with `autoWidth` and `autoHeight` turned on.]],
	arguments = {
		{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
		{ name = "text", type = "string", description = "The text to display." },
	},
	valuetype = "tes3uiElement",
}