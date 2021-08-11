# calcTravelPrice

This event is called when determining the price of traveling, and can be used to modify the given price.

```lua
--- @type e event.calcTravelPrice
local function calcTravelPriceCallback(e)
end
event.register("calcTravelPrice", calcTravelPriceCallback)
```

## Event Data

* `price` (number): The adjusted price of travelling.
* `destination` ([tes3reference](../../types/tes3reference)): The travel marker that marks the destination.
* `reference` ([tes3reference](../../types/tes3reference)): mobile’s related reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor of the merchant the player is interacting with.
* `basePrice` (number): The price before adjustment.
* `companions` (table): A table of companions (tes3references) that will travel with the player, or nil if no companions are present.

