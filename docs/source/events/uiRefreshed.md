# uiRefreshed

This event is invoked after a UI menu has been created or recreated. This can be useful for when important game subcomponents are destroyed and remade, without the entire UI being activated.

**Supported Elements**: `MenuStat_scroll_pane`

```lua
--- @param e uiRefreshedEventData
local function uiRefreshedCallback(e)
end
event.register(tes3.event.uiRefreshed, uiRefreshedCallback)
```

!!! tip
	This event can be filtered based on the **`element.name`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `element` ([tes3uiElement](../../types/tes3uiElement)): *Read-only*. The menu element that was recreated or refreshed. The event is filtered on element.name
* `newlyCreated` (boolean): *Read-only*. true if the menu was created for the first time or destroyed and re-created; false if it was made visible after being hidden. This can be used when adding custom elements to a menu, as elements previously added will still exist if the menu was hidden. If the menu was re-created, the elements will need to be added again.

