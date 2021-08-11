# keyDown

The key event fires when a key is pressed.

```lua
--- @type e event.keyDown
local function keyDownCallback(e)
end
event.register("keyDown", keyDownCallback)
```

This event can be filtered based on the **`keyCode`** event data.

## Event Data

* `keyCode` (number): The scan code of the key that raised the event.
* `isSuperDown` (number): True if super (Windows key) is held.
* `isControlDown` (number): True if control is held.
* `isAltDown` (number): True if alt  is held.

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

