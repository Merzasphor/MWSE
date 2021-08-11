# calcRepairPrice

This event is called when determining the price of repairing an item. It can be used to override the repair cost.

```lua
--- @type e event.calcRepairPrice
local function calcRepairPriceCallback(e)
end
event.register("calcRepairPrice", calcRepairPriceCallback)
```

## Event Data

* `price` (number): The adjusted price of repairing item.
* `itemData` ([tes3item](../../types/tes3item)): Variable node. The data associated with item. This may be nil.
* `reference` ([tes3reference](../../types/tes3reference)): mobile’s related reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor of the merchant the player is interacting with.
* `basePrice` (number): The price before adjustment.
* `item` ([tes3item](../../types/tes3item)): The item to be repaired.

