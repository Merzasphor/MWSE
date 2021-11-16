# powerRecharged

This event triggers when a power is recharged, and may be used again. In Morrowind, powers are a type of spells which may be cast once per day and don't cost any magicka.

```lua
--- @param e powerRechargedEventData
local function powerRechargedCallback(e)
end
event.register("powerRecharged", powerRechargedCallback)
```

!!! tip
	This event can be filtered based on the **`power`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The actor whose power recharged.
* `power` ([tes3spell](../../types/tes3spell)): *Read-only*. A power which recharged.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. Mobile’s associated reference.

