# calcRepairPrice

This event is called when determining the price of repairing an item. It can be used to override the repair cost.

```lua
--- @param e calcRepairPriceEventData
local function calcRepairPriceCallback(e)
end
event.register("calcRepairPrice", calcRepairPriceCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `basePrice` (number): *Read-only*. The price before adjustment.
* `item` ([tes3item](../../types/tes3item)): *Read-only*. The item to be repaired.
* `itemData` ([tes3item](../../types/tes3item)): *Read-only*. Variable node. The data associated with item. This may be nil.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor of the merchant the player is interacting with.
* `price` (number): The adjusted price of repairing item.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. mobile’s related reference.

