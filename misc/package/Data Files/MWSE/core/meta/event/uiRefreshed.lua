--- @meta

--- This event is invoked after a UI menu has been created or recreated. This can be useful for when important game subcomponents are destroyed and remade, without the entire UI being activated.
--- 
--- **Supported Elements**: `MenuStat_scroll_pane`
--- @class uiRefreshedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field element tes3uiElement *Read-only*. The menu element that was recreated or refreshed. The event is filtered on element.name
--- @field newlyCreated boolean *Read-only*. true if the menu was created for the first time or destroyed and re-created; false if it was made visible after being hidden. This can be used when adding custom elements to a menu, as elements previously added will still exist if the menu was hidden. If the menu was re-created, the elements will need to be added again.
