# unequipped

The unequipped event fires after an actor has successfully equipped an item.

```lua
--- @type e event.unequipped
local function unequippedCallback(e)
end
event.register("unequipped", unequippedCallback)
```

## Event Data

* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data of item.
* `reference` ([tes3reference](../../types/tes3reference)): actor’s associated reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor that has unequipped the item.
* `item` ([tes3baseObject](../../types/tes3baseObject)): The object that has been unequipped.
* `actor` ([tes3actor](../../types/tes3actor)): The actor that has unequipped the item.

