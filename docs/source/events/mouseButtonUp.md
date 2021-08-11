# mouseButtonUp

The mouseButtonDown event fires when a button on the mouse is released.

```lua
--- @type e event.mouseButtonUp
local function mouseButtonUpCallback(e)
end
event.register("mouseButtonUp", mouseButtonUpCallback)
```

This event can be filtered based on the **`button`** event data.

## Event Data

* `isSuperDown` (number): True if super (Windows key) is held.
* `button` (number): The button index that was released.
* `isControlDown` (number): True if control is held.
* `isAltDown` (number): True if alt  is held.

