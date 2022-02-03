return {
	type = "method",
	description = [[Creates a horizontal slider.

Slider specific properties can be accessed through the `widget` property. The widget type for sliders is [`tes3uiSlider`](https://mwse.github.io/MWSE/types/tes3uiSlider/).]],
	arguments = {
		{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
		{ name = "current", type = "number", description = "The current value of the slider." },
		{ name = "max", type = "number", description = "The maximum value of the slider." },
		{ name = "step", type = "number", description = "The change in value when clicking the left and right arrow buttons.", optional = true, default = 1 },
		{ name = "jump", type = "number", description = "The change in value when clicking into the empty areas next to the slider handle.", optional = true, default = 5 },
	},
	valuetype = "tes3uiElement",
}