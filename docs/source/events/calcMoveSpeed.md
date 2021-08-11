# calcMoveSpeed

This event is called when an actor’s movement speed is calculated. The event allows modification of this value, to dehardcode actor movement speeds. Invoked after all other movement speed events are finished.

```lua
--- @param e calcMoveSpeedEventData
local function calcMoveSpeedCallback(e)
end
event.register("calcMoveSpeed", calcMoveSpeedCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): mobile’s related reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor whose speed is being calculated.
* `type` (number): The type of movement that was calculated. This is always 0 for this event.
* `speed` (number): The previous speed calculated, starting with the base engine values.

## Examples

!!! example "Example: 20% Faster Player Movement"

	```lua
	local function onCalcMoveSpeed(e)
	    if (e.reference == tes3.player) then
	        e.speed = e.speed * 1.2
	    end
	end
	event.register(tes3.event.calcMoveSpeed, onCalcMoveSpeed)

	```

