# enchantChargeUse

This event is triggered just before an on-strike or on-use enchantment is used by any actor, and also by the UI system to label enchant charges. It allows modification of the charge required to use an enchantment.

```lua
--- @param e enchantChargeUseEventData
local function enchantChargeUseCallback(e)
end
event.register("enchantChargeUse", enchantChargeUseCallback)
```

!!! tip
	This event can be filtered based on the **`caster`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `caster` ([tes3reference](../../types/tes3reference)): *Read-only*. The caster of the enchantment.
* `charge` (number): The charge required to cast the enchantment. May be modified.
* `isCast` (boolean): True if the calculation is for a on-strike or on-use action, false if for UI enchant charge display. The type of action is found at e.source.castType.
* `source` ([tes3enchantment](../../types/tes3enchantment)): *Read-only*. The enchantment being used or examined by the UI.

