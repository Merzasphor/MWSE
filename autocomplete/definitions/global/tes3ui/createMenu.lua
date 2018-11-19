return {
	type = "function",
	description = [[Creates a top-level menu.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "id", type = "number", description = "The menu’s ID. The menu can be later accessed by tes3ui.findMenu(id)." },
			{ name = "dragFrame", type = "boolean", default = false, description = "Constructs a draggable and resizeable frame and background for the menu. It is similar to the stats, inventory, magic and map menus in the standard UI. After construction, position and minimum dimensions should be set." },
			{ name = "fixedFrame", type = "boolean", default = false, description = "Constructs a fixed (non-draggable) frame and background for the menu. The layout system should automatically centre and size it to fit whatever is added to the menu." },
		},
	}},
	returns = "tes3uiElement",
}
