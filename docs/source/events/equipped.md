# equipped

The **equipped** event fires after an actor has successfully equipped an item. This event is preceded by the [equip](https://mwse.github.io/MWSE/events/equip) event.

```lua
--- @param e equippedEventData
local function equippedCallback(e)
end
event.register(tes3.event.equipped, equippedCallback)
```

!!! tip
	This event can be filtered based on the **`item`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `actor` ([tes3actor](../../types/tes3actor)): *Read-only*. The actor that has equipped the item.
* `item` ([tes3baseObject](../../types/tes3baseObject)): *Read-only*. The object that has been equipped.
* `itemData` ([tes3itemData](../../types/tes3itemData)): *Read-only*. The item data of item.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that has equipped the item.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference to the mobile actor that has equipped the item.

