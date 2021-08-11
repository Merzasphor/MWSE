# calcArmorPieceHit

This event is raised just after determining which armor piece, if any, was hit with an attack. The slots can be modified, to draw focus onto specific armor slots.

```lua
--- @type e event.calcArmorPieceHit
local function calcArmorPieceHitCallback(e)
end
event.register("calcArmorPieceHit", calcArmorPieceHitCallback)
```

This event can be filtered based on the **`reference.baseObject`** event data.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): A shortcut to the mobile's reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile who is being hit.
* `slot` (number): The primary slot that is targeted.
* `fallback` (number): A secondary slot to check for equipment on, if no armor is found using the primary slot.

