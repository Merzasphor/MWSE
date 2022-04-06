return {
	type = "value",
	readOnly = true,
	description = [[The root element of the help UI layer. The help UI layer will always be drawn after the main UI layer and therefore all elements on it will be shown in front of elements of the main UI layer. This element contains top level menus like tooltips, message boxes and more as direct children. Prefer using the [`tes3ui.findHelpLayerMenu()`](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uifindhelplayermenu) function to find one of this element's direct children.]],
	valuetype = "tes3uiElement",
}