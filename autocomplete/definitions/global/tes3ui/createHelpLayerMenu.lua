return {
	type = "function",
	description = [[Creates a help layer menu. Help layer menus include notifications and tooltips that are always above the rest of the interface. The game realizes this using a separate menu root and set of functions.

Note, to create tooltips with the correct behaviour, use tes3ui.createTooltipMenu.

Unlike standard menus, help layer menus are always created with a fixed frame.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "string|number", description = "The menu’s ID. The menu can be later accessed by tes3ui.findHelpLayerMenu(id)." },
		},
	}},
	valuetype = "tes3uiElement",
}
