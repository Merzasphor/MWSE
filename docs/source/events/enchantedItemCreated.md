# enchantedItemCreated

This event is fired when an enchanted item has been created by the player.

```lua
--- @param e enchantedItemCreatedEventData
local function enchantedItemCreatedCallback(e)
end
event.register(tes3.event.enchantedItemCreated, enchantedItemCreatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `baseObject` ([tes3item](../../types/tes3item)): *Read-only*. The item originally enchanted.
* `enchanter` (tes3mobile): The mobile actor responsible for creating the enchantment.
* `enchanterReference` ([tes3reference](../../types/tes3reference)): The reference responsible for creating the enchantment.
* `object` ([tes3item](../../types/tes3item)): *Read-only*. The newly created and enchanted item.
* `soul` ([tes3actor](../../types/tes3actor)): The actor used to enchant the item.
* `soulGem` ([tes3misc](../../types/tes3misc)): The soul gem used for the creation of the item.

