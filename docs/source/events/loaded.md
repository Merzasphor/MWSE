# loaded

The loaded event fires after the game has been successfully loaded. This event is preceded by the load event.

```lua
--- @param e loadedEventData
local function loadedCallback(e)
end
event.register(tes3.event.loaded, loadedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `filename` (string): *Read-only*. The filename of the save that was loaded, not including file extension.
* `newGame` (boolean): *Read-only*. If true, a new game was started.
* `quickload` (boolean): *Read-only*. If true, the load came from the quickload system.

