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

* `reference` ([tes3reference](../../types/tes3reference)): Mobile’s associated reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): 
* `power` ([tes3spell](../../types/tes3spell)): 

