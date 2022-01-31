# uiShowRestMenu

The uiShowRestMenu event is raised when the rest menu is about to be displayed. It allows the callback to change if sleeping is allowed, or to prevent the UI from showing at all.

```lua
--- @param e uiShowRestMenuEventData
local function uiShowRestMenuCallback(e)
end
event.register(tes3.event.uiShowRestMenu, uiShowRestMenuCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `allowRest` (boolean): true if the player is allowed to sleep (determined primarily from the cell flags), or false if they must wait instead. This value can be modified.
* `scripted` (boolean): *Read-only*. This value is true when the menu is shown from using the ShowRestMenu or equivalent function.

