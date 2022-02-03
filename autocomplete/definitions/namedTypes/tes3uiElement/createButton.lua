return {
	type = "method",
	description = [[Creates a clickable button. Register the `mouseClick` event to capture a button press.

Button specific properties can be accessed through the `widget` property. The widget type for buttons is [`tes3uiButton`](https://mwse.github.io/MWSE/types/tes3uiButton/).]],
	arguments = {
		{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
	},
	valuetype = "tes3uiElement",
}