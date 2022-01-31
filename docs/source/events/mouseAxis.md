# mouseAxis

The mouseAxis event fires when the mouse is moved, providing deltaX and deltaY values.

```lua
--- @param e mouseAxisEventData
local function mouseAxisCallback(e)
end
event.register(tes3.event.mouseAxis, mouseAxisCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `deltaX` (number): *Read-only*. The difference in horizontal mouse position from the previous frame.
* `deltaY` (number): *Read-only*. The difference in vertical mouse position from the previous frame.
* `isAltDown` (number): *Read-only*. True if alt  is held.
* `isControlDown` (number): *Read-only*. True if control is held.
* `isSuperDown` (number): *Read-only*. True if super (Windows key) is held.

