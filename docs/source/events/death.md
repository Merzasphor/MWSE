# death

This event triggers when an actor dies.

```lua
--- @param e deathEventData
local function deathCallback(e)
end
event.register(tes3.event.death, deathCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that has died.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. mobile’s associated reference.

