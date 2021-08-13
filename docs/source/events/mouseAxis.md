# mouseAxis

The mouseAxis event fires when the mouse is moved, providing deltaX and deltaY values.

```lua
--- @param e mouseAxisEventData
local function mouseAxisCallback(e)
end
event.register("mouseAxis", mouseAxisCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `deltaX` (number): The difference in horizontal mouse position from the previous frame.
* `deltaY` (number): The difference in vertical mouse position from the previous frame.
* `isAltDown` (number): True if alt  is held.
* `isControlDown` (number): True if control is held.
* `isSuperDown` (number): True if super (Windows key) is held.

