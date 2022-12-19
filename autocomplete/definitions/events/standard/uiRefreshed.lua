return {
	type = "event",
	description = [[This event is invoked after a UI menu has been created or recreated. This can be useful for when important game subcomponents are destroyed and remade, without the entire UI being activated.

**Supported Elements**: `MenuStat_scroll_pane`]],
	eventData = {
		["element"] = {
			type = "tes3uiElement",
			readOnly = true,
			description = "The menu element that was recreated or refreshed. The event is filtered on element.name",
		},
	},
	filter = "element.name",
}