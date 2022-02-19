# collision

This event is triggered on a collision and all the frames during the collision.

```lua
--- @param e collisionEventData
local function collisionCallback(e)
end
event.register(tes3.event.collision, collisionCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileObject](../../types/tes3mobileObject)): *Read-only*. Mobile object which collided with its target reference.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. Mobile object's associated reference.
* `target` ([tes3reference](../../types/tes3reference)): *Read-only*. Reference which mobile object has collided with.

## Examples

!!! example "Example: Shows a message when the player bumps into the door."

	```lua
	
	local function onCollision(e)
		if e.reference ~= tes3.player then
			return
		end
	
		local target = e.target
		if not target then
			return
		end
	
		if target.object.objectType == tes3.objectType.door then
			tes3.messageBox("Ouch!\nMaybe I should open it first?")
		end
	end
	
	event.register("collision", onCollision)

	```

