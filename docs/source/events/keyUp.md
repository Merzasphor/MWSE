# keyUp

The key event fires when a key is released.

```lua
--- @param e keyUpEventData
local function keyUpCallback(e)
end
event.register(tes3.event.keyUp, keyUpCallback)
```

!!! tip
	This event can be filtered based on the **`keyCode`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `isAltDown` (number): *Read-only*. True if either alt key is held.
* `isControlDown` (number): *Read-only*. True if either control key is held.
* `isShiftDown` (number): *Read-only*. True if either shift key is held.
* `isSuperDown` (number): *Read-only*. True if super (Windows key) is held.
* `keyCode` (number): *Read-only*. The scan code of the key that raised the event.

