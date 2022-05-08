return {
	type = "method",
	description = [[Creates a textured horizontal divider line, as used in the magic and stat menus. Scales automatically to the container width.]],
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
