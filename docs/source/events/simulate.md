# simulate

The simulate event occurs at the start of every frame, excluding when the game is paused or in menu mode.

```lua
--- @param e simulateEventData
local function simulateCallback(e)
end
event.register("simulate", simulateCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `timestamp` (number): The number of hours since the beginning of the 3rd Era (similar to the Unix Epoch).
* `menuMode` (boolean): Always false, maintained only for consistency with the enterFrame event.
* `delta` (number): The number of seconds since the last frame.

