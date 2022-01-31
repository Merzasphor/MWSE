# calcBarterPrice

This event is raised when an item price is being determined when bartering.

```lua
--- @param e calcBarterPriceEventData
local function calcBarterPriceCallback(e)
end
event.register(tes3.event.calcBarterPrice, calcBarterPriceCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `basePrice` (number): *Read-only*. The base price of the item, before any event modifications.
* `buying` (boolean): *Read-only*. If true, the player is buying, otherwise the player is selling.
* `count` (number): *Read-only*. The number of items being bartered.
* `item` ([tes3item](../../types/tes3item)): *Read-only*. The item, if any, that is being bartered.
* `itemData` ([tes3itemData](../../types/tes3itemData)): *Read-only*. The item data for the bartered item.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor for who is selling or buying. May not always be available.
* `price` (number): The price of the item. This can be modified, but ensure that the buy/sell price is matched or there will be odd behavior.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. A shortcut to the mobile's reference. May not always be available.

