# combatStopped

The combatStopped event occurs after an actor has left combat.

```lua
--- @param e combatStoppedEventData
local function combatStoppedCallback(e)
end
event.register("combatStopped", combatStoppedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `actor` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor who has left combat.

