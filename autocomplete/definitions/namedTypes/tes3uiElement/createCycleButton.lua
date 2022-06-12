return {
	type = "method",
	description = [[Creates a clickable button, whose text changes linearly through options as it is clicked. Register the `valueChanged` event for when the option is cycled or changed via script.

Button specific properties can be accessed through the `widget` property. The widget type for buttons is [`tes3uiCycleButton`](https://mwse.github.io/MWSE/types/tes3uiCycleButton/).]],
	arguments = { {
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
			{ name = "options", type = "tes3uiCycleButtonOption[]", description = "An array of options for the button to cycle through. At minimum the option must have a `text` property defined, to show on the button. If a `value` is provided, it can be accessed through the `.widget`'s `.value` property." },
			{ name = "index", type = "number", optional = true, description = "The index selected by default." },
		},
	} },
	valuetype = "tes3uiElement",
}
