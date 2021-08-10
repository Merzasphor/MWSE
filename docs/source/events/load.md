# load

The load event fires when the game is about to load. This event allows scripts to block loading.

```lua
--- @type e event.load
local function loadCallback(e)
end
event.register("load", loadCallback)
```

This event can be filtered based on the **`filename`** event data.

## Event Data

* `filename` (string): The filename of the save we want to load, not including file extension. Can be modified to redirect to another save.
* `quickload` (boolean): If true, the load came from the quickload system.
* `newGame` (boolean): If true, a new game is being started.

