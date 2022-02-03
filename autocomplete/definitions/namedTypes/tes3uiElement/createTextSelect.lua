return {
	type = "method",
	description = [[Creates a selectable line of text, with configurable hover, click, and disabled colours. Can be used to create a list box by placing them in a ScrollPane.
	
Text select specific properties can be accessed through the `widget` property. The widget type for text selects is [`tes3uiTextSelect`](https://mwse.github.io/MWSE/types/tes3uiTextSelect/).]],
	arguments = {
		{ name = "id", type = "string|number", description = "An identifier to help find this element later.", optional = true },
		{ name = "text", type = "string", description = "The text to display.", optional = true },
		{ name = "state", type = "number", description = "The initial interaction state.", default = "tes3.uiState.normal", optional = true },
	},
	valuetype = "tes3uiElement",
}