return {
	type = "method",
	description = [[Creates a multi-line text input element, with line wrapping on. To receive input the keyboard must be captured with `tes3ui.acquireTextInput(element)`. Read the input with the `text` property. Write an initial value to edit by setting the `text` property.

Paragraph input specific properties can be accessed through the `widget` property. The widget type for paragraph inputs is [`tes3uiParagraphInput`](https://mwse.github.io/MWSE/types/tes3uiParagraphInput/).]],
	arguments = {
		{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
	},
	valuetype = "tes3uiElement",
}