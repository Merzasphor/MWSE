# uiActivated

This event is invoked after a UI menu has been built or made visible, at the point that all menu elements contain updated data.

```lua
--- @param e uiActivatedEventData
local function uiActivatedCallback(e)
end
event.register("uiActivated", uiActivatedCallback)
```

!!! tip
	This event can be filtered based on the **`element.name`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `element` ([tes3uiElement](../../types/tes3uiElement)): *Read-only*. The menu element that was created. The event is filtered on element.name.
* `newlyCreated` (boolean): *Read-only*. true if the menu was created for the first time or destroyed and re-created; false if it was made visible after being hidden. This can be used when adding custom elements to a menu, as elements previously added will still exist if the menu was hidden. If the menu was re-created, the elements will need to be added again.

