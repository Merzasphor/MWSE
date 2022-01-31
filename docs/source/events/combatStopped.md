# combatStopped

The **combatStopped** event occurs after an actor has left combat. This event is preceded by the [combatStop](https://mwse.github.io/MWSE/events/combatStop) event.

```lua
--- @param e combatStoppedEventData
local function combatStoppedCallback(e)
end
event.register(tes3.event.combatStopped, combatStoppedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `actor` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor who has left combat.

