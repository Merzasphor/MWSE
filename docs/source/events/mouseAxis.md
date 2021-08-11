# mouseAxis

The mouseAxis event fires when the mouse is moved, providing deltaX and deltaY values.

```lua
--- @type e event.mouseAxis
local function mouseAxisCallback(e)
end
event.register("mouseAxis", mouseAxisCallback)
```

## Event Data

* `isSuperDown` (number): True if super (Windows key) is held.
* `deltaY` (number): The difference in vertical mouse position from the previous frame.
* `isControlDown` (number): True if control is held.
* `isAltDown` (number): True if alt  is held.
* `deltaX` (number): The difference in horizontal mouse position from the previous frame.

