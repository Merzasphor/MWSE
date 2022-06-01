return {
	type = "function",
	description = [[Creates a top-level menu.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "string|number", description = "The menu’s ID. The menu can be later accessed by tes3ui.findMenu(id)." },
			{ name = "dragFrame", type = "boolean", default = false, description = "Constructs a draggable and resizeable frame and background for the menu. It is similar to the stats, inventory, magic and map menus in the standard UI. Its title bar text can be set with the .text property. After construction, position and minimum dimensions should be set." },
			{ name = "fixedFrame", type = "boolean", default = false, description = "Constructs a fixed (non-draggable) frame and background for the menu. The layout system should automatically centre and size it to fit whatever is added to the menu. This type of menu is modal by default, preventing interaction with other menus while the menu is active." },
			{ name = "modal", type = "boolean", default = true, description = "Only applies to fixedFrame menus. Modal menus prevent interaction with other menus while the menu is active. This behavior can be disabled with this flag." },
			{ name = "loadable", type = "boolean", default = true, description = "If set to false, calls to loadMenuPosition will fail." },
		},
	}},
	valuetype = "tes3uiElement",
}
