# mouseButtonDown

The mouseButtonDown event fires when a button on the mouse is pressed.

```lua
--- @param e mouseButtonDownEventData
local function mouseButtonDownCallback(e)
end
event.register("mouseButtonDown", mouseButtonDownCallback)
```

This event can be filtered based on the **`button`** event data.

## Event Data

* `isSuperDown` (number): True if super (Windows key) is held.
* `button` (number): The button index that was pressed.
* `isControlDown` (number): True if control is held.
* `isAltDown` (number): True if alt  is held.

