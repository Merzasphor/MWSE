# equipmentReevaluated

The **equipmentReevaluated** event fires after an actor has gone through its items and determined if anything in its inventory is better than what it currently has equipped. This event can be used to force equip new, custom equipment slots if needed.

```lua
--- @param e equipmentReevaluatedEventData
local function equipmentReevaluatedCallback(e)
end
event.register(tes3.event.equipmentReevaluated, equipmentReevaluatedCallback)
```

!!! tip
	This event can be filtered based on the **`item`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `actor` ([tes3actor](../../types/tes3actor)): *Read-only*. The actor that has reevaluated their equipment.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that has reevaluated their equipment.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference that has reevaluated their equipment.

