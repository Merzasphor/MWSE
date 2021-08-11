# enterFrame

The enterFrame event occurs at the start of every frame, including when the game is paused or in menu mode.

```lua
--- @param e enterFrameEventData
local function enterFrameCallback(e)
end
event.register("enterFrame", enterFrameCallback)
```

## Event Data

* `timestamp` (number): The number of hours since the beginning of the 3rd Era (similar to the Unix Epoch).
* `menuMode` (boolean): If the game is paused- in the inventory or a menu, etc.
* `delta` (number): The number of seconds since the last frame.

