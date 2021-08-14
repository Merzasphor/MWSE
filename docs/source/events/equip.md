# equip

The equip event fires when an actor is about to equip an item, i.e. just before the item is equipped. This event allows scripts to block equipping. See `equipped`_ for the post-equip event.

The item must not be removed from the inventory during this event, as the item and item data is still being referenced by the initiator of the equip action. If you want to consume the item, block the equip and remove it at a later time. Removing the item during this event can cause inventory desync bugs.

```lua
--- @param e equipEventData
local function equipCallback(e)
end
event.register("equip", equipCallback)
```

!!! tip
	This event can be filtered based on the **`item`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `item` ([tes3baseObject](../../types/tes3baseObject)): *Read-only*. The object being equipped.
* `itemData` ([tes3itemData](../../types/tes3itemData)): *Read-only*. The item data of item.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference to the mobile actor that is equipping the item.

