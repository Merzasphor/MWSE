# mouseButtonDown

The mouseButtonDown event fires when a button on the mouse is pressed.

```lua
--- @param e mouseButtonDownEventData
local function mouseButtonDownCallback(e)
end
event.register("mouseButtonDown", mouseButtonDownCallback)
```

!!! tip
	This event can be filtered based on the **`button`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `button` (number): *Read-only*. The button index that was pressed.
* `isAltDown` (number): *Read-only*. True if alt  is held.
* `isControlDown` (number): *Read-only*. True if control is held.
* `isSuperDown` (number): *Read-only*. True if super (Windows key) is held.

