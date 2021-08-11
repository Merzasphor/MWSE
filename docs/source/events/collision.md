# collision

This event is triggered on a collision.

```lua
--- @type e event.collision
local function collisionCallback(e)
end
event.register("collision", collisionCallback)
```

This event can be filtered based on the **`reference`** event data.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): Mobile object's associated reference.
* `mobile` ([tes3mobileObject](../../types/tes3mobileObject)): Mobile object which collided with its target reference.
* `target` ([tes3reference](../../types/tes3reference)): Reference which mobile object has collided with.

