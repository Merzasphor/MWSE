return {
	type = "function",
	description = [[Creates a tooltip menu, which can be an empty menu, an item tooltip, or a spell tooltip. This should be called from within a tooltip event callback. These automatically follow the mouse cursor, and are also destroyed automatically when the mouse leaves the originating element. Creating an item tooltip will invoke the uiObjectTooltip event.]],
	arguments = {{
		name = "params",
		type = "table",
		optional = true,
		tableParams = {
			{ name = "item", type = "tes3item|string", optional = true, description = "The item to create a tooltip for. If not specified, the tooltip will be empty." },
			{ name = "itemData", type = "tes3itemData", optional = true, description = "The item data for the item." },
			{ name = "spell", type = "tes3spell", optional = true, description = "The spell to create a tooltip for." },
		},
	}},
	valuetype = "tes3uiElement",
	examples = {
		["itemTooltip"] = {
			title = "Add an item tooltip to a new element",
			description = "This demonstrates adding an item tooltip to a button using the help event."
		},
	}
}
