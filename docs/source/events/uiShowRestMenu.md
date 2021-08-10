# uiShowRestMenu

The uiShowRestMenu event is raised when the rest menu is about to be displayed. It allows the callback to change if sleeping is allowed, or to prevent the UI from showing at all.

```lua
--- @type e event.uiShowRestMenu
local function uiShowRestMenuCallback(e)
end
event.register("uiShowRestMenu", uiShowRestMenuCallback)
```

## Event Data

* `allowRest` (boolean): true if the player is allowed to sleep (determined primarily from the cell flags), or false if they must wait instead. This value can be modified.
* `scripted` (boolean): This value is true when the menu is shown from using the ShowRestMenu or equivalent function.

