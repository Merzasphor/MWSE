# keyUp

The key event fires when a key is released.

```lua
--- @param e keyUpEventData
local function keyUpCallback(e)
end
event.register("keyUp", keyUpCallback)
```

!!! tip
	This event can be filtered based on the **`keyCode`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `keyCode` (number): The scan code of the key that raised the event.
* `isSuperDown` (number): True if super (Windows key) is held.
* `isControlDown` (number): True if control is held.
* `isAltDown` (number): True if alt  is held.

