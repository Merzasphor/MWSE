# equipped

The equipped event fires after an actor has successfully equipped an item.

```lua
--- @type e event.equipped
local function equippedCallback(e)
end
event.register("equipped", equippedCallback)
```

This event can be filtered based on the **`item`** event data.

## Event Data

* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data of item.
* `reference` ([tes3reference](../../types/tes3reference)): The reference to the mobile actor that has equipped the item.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor that has equipped the item.
* `item` ([tes3baseObject](../../types/tes3baseObject)): The object that has been equipped.
* `actor` ([tes3actor](../../types/tes3actor)): The actor that has equipped the item.

