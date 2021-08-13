# save

The save event fires when the game is about to save. This event allows scripts to block saving.

```lua
--- @param e saveEventData
local function saveCallback(e)
end
event.register("save", saveCallback)
```

!!! tip
	This event can be filtered based on the **`filename`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `filename` (string): The filename of the save, not including file extension.
* `name` (string): The user facing name of the save, shown in the load/save game menu.

