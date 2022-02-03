return {
	type = "method",
	description = [[Creates a single line text input element. To receive input the keyboard must be captured with `tes3ui.acquireTextInput(element)`. Read the input with the `text` property. Write an initial value to display by setting the `text` property; that value will be cleared on the first keypress.

Text input specific properties can be accessed through the `widget` property. The widget type for text inputs is [`tes3uiTextInput`](https://mwse.github.io/MWSE/types/tes3uiTextInput/).]],
	arguments = {
		{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
	},
	valuetype = "tes3uiElement",
}