# enterFrame

The enterFrame event occurs at the start of every frame, including when the game is paused or in menu mode.

```lua
--- @param e enterFrameEventData
local function enterFrameCallback(e)
end
event.register(tes3.event.enterFrame, enterFrameCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `delta` (number): *Read-only*. The number of seconds since the last frame.
* `menuMode` (boolean): *Read-only*. If the game is paused- in the inventory or a menu, etc.
* `timestamp` (number): *Read-only*. The number of hours since the beginning of the 3rd Era (similar to the Unix Epoch).

