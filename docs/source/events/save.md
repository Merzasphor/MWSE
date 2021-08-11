# save

The save event fires when the game is about to save. This event allows scripts to block saving.

```lua
--- @param e saveEventData
local function saveCallback(e)
end
event.register("save", saveCallback)
```

This event can be filtered based on the **`filename`** event data.

## Event Data

* `name` (string): The user facing name of the save, shown in the load/save game menu.
* `filename` (string): The filename of the save, not including file extension.

