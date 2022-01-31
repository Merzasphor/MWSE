# mouseWheel

The mouseWheel event fires when the mouse wheel is used, providing a delta value.

```lua
--- @param e mouseWheelEventData
local function mouseWheelCallback(e)
end
event.register(tes3.event.mouseWheel, mouseWheelCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `delta` (number): *Read-only*. The direction and strength of the mouse wheel movement. This value is hardware dependent.
* `isAltDown` (number): *Read-only*. True if alt is held.
* `isControlDown` (number): *Read-only*. True if control is held.
* `isSuperDown` (number): *Read-only*. True if super (Windows key) is held.

