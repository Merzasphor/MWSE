# keyUp

The key event fires when a key is released.

```lua
--- @type e event.keyUp
local function keyUpCallback(e)
end
event.register("keyUp", keyUpCallback)
```

This event can be filtered based on the **`keyCode`** event data.

## Event Data

* `keyCode` (number): The scan code of the key that raised the event.
* `isSuperDown` (number): True if super (Windows key) is held.
* `isControlDown` (number): True if control is held.
* `isAltDown` (number): True if alt  is held.

