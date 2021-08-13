# unequipped

The unequipped event fires after an actor has successfully equipped an item.

```lua
--- @param e unequippedEventData
local function unequippedCallback(e)
end
event.register("unequipped", unequippedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `actor` ([tes3actor](../../types/tes3actor)): The actor that has unequipped the item.
* `item` ([tes3baseObject](../../types/tes3baseObject)): The object that has been unequipped.
* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data of item.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor that has unequipped the item.
* `reference` ([tes3reference](../../types/tes3reference)): actor’s associated reference.

