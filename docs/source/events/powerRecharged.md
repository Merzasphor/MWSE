# powerRecharged



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

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. 
* `power` ([tes3spell](../../types/tes3spell)): *Read-only*. 
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. Mobile’s associated reference.

