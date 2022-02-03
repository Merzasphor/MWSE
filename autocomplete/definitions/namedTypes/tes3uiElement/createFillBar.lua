return {
	type = "method",
	description = [[Creates a horizontal quantity indicator bar.

Fillbar specific properties can be accessed through the `widget` property. The widget type for fillbars is [`tes3uiFillBar`](https://mwse.github.io/MWSE/types/tes3uiFillBar/).]],
	arguments = {
		{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
		{ name = "current", type = "number", description = "The current value of the fillbar.", optional = true },
		{ name = "max", type = "number", description = "The maximum value of the fillbar.", optional = true },
	},
	valuetype = "tes3uiElement",
}