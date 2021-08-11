# calcArmorRating

This event is fired before an actor's armor rating has been calculated, and can be used to override the armor that the actor is given.

```lua
--- @param e calcArmorRatingEventData
local function calcArmorRatingCallback(e)
end
event.register("calcArmorRating", calcArmorRatingCallback)
```

!!! tip
	This event can be filtered based on the **`armor`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `npc` ([tes3npc](../../types/tes3npc)): The NPC object whose AR is being calculated. May not always be available.
* `reference` ([tes3reference](../../types/tes3reference)): A shortcut to the mobile's reference. May not always be available.
* `armorRating` (number): If set, the given armor rating will be used instead of the one calculated.
* `armor` ([tes3armor](../../types/tes3armor)): The armor piece whose AR is being calculated.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile whose AR is being calculated. May not always be available.

