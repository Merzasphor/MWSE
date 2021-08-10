# saved

The saved event fires after the game has successfully been saved. This event is preceded by the save event.

```lua
--- @type e event.saved
local function savedCallback(e)
end
event.register("saved", savedCallback)
```

## Event Data

* `name` (string): The user facing name of the save, shown in the load/save game menu.
* `filename` (string): The filename of the save, not including file extension.

