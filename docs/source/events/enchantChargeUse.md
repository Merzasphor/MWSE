# enchantChargeUse

This event is triggered just before an on-strike or on-use enchantment is used by any actor, and also by the UI system to label enchant charges. It allows modification of the charge required to use an enchantment.

```lua
--- @type e event.enchantChargeUse
local function enchantChargeUseCallback(e)
end
event.register("enchantChargeUse", enchantChargeUseCallback)
```

This event can be filtered based on the **`caster`** event data.

## Event Data

* `isCast` (boolean): True if the calculation is for a on-strike or on-use action, false if for UI enchant charge display. The type of action is found at e.source.castType.
* `charge` (number): The charge required to cast the enchantment. May be modified.
* `caster` ([tes3reference](../../types/tes3reference)): The caster of the enchantment.
* `source` ([tes3enchantment](../../types/tes3enchantment)): The enchantment being used or examined by the UI.

