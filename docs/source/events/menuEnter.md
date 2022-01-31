# menuEnter

The menuEnter event fires when the player enters menu mode.

```lua
--- @param e menuEnterEventData
local function menuEnterCallback(e)
end
event.register(tes3.event.menuEnter, menuEnterCallback)
```

!!! tip
	This event can be filtered based on the **`menu.name`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `menu` ([tes3uiElement](../../types/tes3uiElement)): *Read-only*. The new top-level menu.
* `menuMode` (boolean): *Read-only*. Always true for this event. This parameter is only useful when registering the same callback for menuEnter and menuExit events.

