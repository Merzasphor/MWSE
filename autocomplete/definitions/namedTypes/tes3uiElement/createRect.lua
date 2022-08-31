return {
	type = "method",
	description = [[Creates a filled rectangle. The rectangle is displayed as filled with the element's color. It supports alpha compositing.]],
	arguments = { {
		name = "params",
		type = "table",
		optional = true,
		tableParams = {
			{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
			{ name = "color", type = "tes3vector3|table", description = "The fill color for the element.", optional = true },
			{ name = "randomizeColor", type = "boolean", optional = true, default = false, description = "If true, the creation color will be randomized." },
		},
	} },
	valuetype = "tes3uiElement",
}
