# equip

The equip event fires when an actor is about to equip an item, i.e. just before the item is equipped. This event allows scripts to block equipping. See `equipped`_ for the post-equip event.

The item must not be removed from the inventory during this event, as the item and item data is still being referenced by the initiator of the equip action. If you want to consume the item, block the equip and remove it at a later time. Removing the item during this event can cause inventory desync bugs.

```lua
--- @param e equipEventData
local function equipCallback(e)
end
event.register("equip", equipCallback)
```

This event can be filtered based on the **`item`** event data.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): The reference to the mobile actor that is equipping the item.
* `item` ([tes3baseObject](../../types/tes3baseObject)): The object being equipped.
* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data of item.

