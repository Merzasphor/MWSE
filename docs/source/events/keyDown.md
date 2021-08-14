# keyDown

The key event fires when a key is pressed.

```lua
--- @param e keyDownEventData
local function keyDownCallback(e)
end
event.register("keyDown", keyDownCallback)
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

## Examples

!!! example "Example: Show a Message when Ctrl-Z is Pressed"

	```lua
	function myOnKeyCallback(e)
	    if( e.isControlDown ) then
	        tes3.messageBox({ message = "You pressed Ctrl-Z, but you can't undo all your mistakes." })
	    end
	end
	
	-- Filter by the scan code to get Z key presses only.
	event.register("key", myOnKeyCallback, { filter = tes3.scanCode.z } )

	```

