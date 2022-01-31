# bodyPartsUpdated

This event is triggered when an actor's body parts have finished updating. This typically triggers when an actor is first rendered, or when their equipment changes.

```lua
--- @param e bodyPartsUpdatedEventData
local function bodyPartsUpdatedCallback(e)
end
event.register(tes3.event.bodyPartsUpdated, bodyPartsUpdatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor whose body parts were updated.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference for the actor whose body parts were updated.

