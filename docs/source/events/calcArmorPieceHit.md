# calcArmorPieceHit

This event is raised just after determining which armor piece, if any, was hit with an attack. The slots can be modified, to draw focus onto specific armor slots.

```lua
--- @param e calcArmorPieceHitEventData
local function calcArmorPieceHitCallback(e)
end
event.register("calcArmorPieceHit", calcArmorPieceHitCallback)
```

!!! tip
	This event can be filtered based on the **`reference.baseObject`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `fallback` (number): A secondary slot to check for equipment on, if no armor is found using the primary slot.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile who is being hit.
* `reference` ([tes3reference](../../types/tes3reference)): A shortcut to the mobile's reference.
* `slot` (number): The primary slot that is targeted.

