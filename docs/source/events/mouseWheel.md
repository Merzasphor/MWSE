# mouseWheel

The mouseWheel event fires when the mouse wheel is used, providing a delta value.

```lua
--- @type e event.mouseWheel
local function mouseWheelCallback(e)
end
event.register("mouseWheel", mouseWheelCallback)
```

## Event Data

* `isSuperDown` (number): True if super (Windows key) is held.
* `isAltDown` (number): True if alt is held.
* `isControlDown` (number): True if control is held.
* `delta` (number): The direction and strength of the mouse wheel movement. This value is hardware dependent.

