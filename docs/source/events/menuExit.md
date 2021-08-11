# menuExit

The menuExit event fires when the player leaves menu mode.

```lua
--- @type e event.menuExit
local function menuExitCallback(e)
end
event.register("menuExit", menuExitCallback)
```

## Event Data

* `menuMode` (boolean): Always true for this event. This parameter is only useful when registering the same callback for menuEnter and menuExit events.

