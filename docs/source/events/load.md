# load

The load event fires when the game is about to load. This event allows scripts to block loading.

```lua
--- @param e loadEventData
local function loadCallback(e)
end
event.register("load", loadCallback)
```

!!! tip
	This event can be filtered based on the **`filename`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `filename` (string): The filename of the save we want to load, not including file extension. Can be modified to redirect to another save.
* `newGame` (boolean): *Read-only*. If true, a new game is being started.
* `quickload` (boolean): *Read-only*. If true, the load came from the quickload system.

