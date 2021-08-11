# powerRecharged



```lua
--- @param e powerRechargedEventData
local function powerRechargedCallback(e)
end
event.register("powerRecharged", powerRechargedCallback)
```

This event can be filtered based on the **`power`** event data.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): Mobile’s associated reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): 
* `power` ([tes3spell](../../types/tes3spell)): 

