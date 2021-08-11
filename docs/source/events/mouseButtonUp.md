# mouseButtonUp

The mouseButtonDown event fires when a button on the mouse is released.

```lua
--- @param e mouseButtonUpEventData
local function mouseButtonUpCallback(e)
end
event.register("mouseButtonUp", mouseButtonUpCallback)
```

!!! tip
	This event can be filtered based on the **`button`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `isSuperDown` (number): True if super (Windows key) is held.
* `button` (number): The button index that was released.
* `isControlDown` (number): True if control is held.
* `isAltDown` (number): True if alt  is held.

