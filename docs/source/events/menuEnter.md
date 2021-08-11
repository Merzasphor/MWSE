# menuEnter

The menuEnter event fires when the player enters menu mode.

```lua
--- @type e event.menuEnter
local function menuEnterCallback(e)
end
event.register("menuEnter", menuEnterCallback)
```

This event can be filtered based on the **`menu.name`** event data.

## Event Data

* `menuMode` (boolean): Always true for this event. This parameter is only useful when registering the same callback for menuEnter and menuExit events.
* `menu` ([tes3uiElement](../../types/tes3uiElement)): The new top-level menu.

