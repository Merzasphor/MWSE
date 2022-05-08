return {
	type = "method",
	description = [[Creates a styled thin border element. Any content should be created as children of this border.]],
	arguments = { {
		name = "params",
		type = "table",
		optional = true,
		tableParams = {
			{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
		},
	} },
	valuetype = "tes3uiElement",
}
