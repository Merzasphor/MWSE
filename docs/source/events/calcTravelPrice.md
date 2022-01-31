# calcTravelPrice

This event is called when determining the price of traveling, and can be used to modify the given price.

```lua
--- @param e calcTravelPriceEventData
local function calcTravelPriceCallback(e)
end
event.register(tes3.event.calcTravelPrice, calcTravelPriceCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `basePrice` (number): *Read-only*. The price before adjustment.
* `companions` (table): *Read-only*. A table of companions (`tes3reference`s) that will travel with the player, or `nil` if no companions are present.
* `destination` ([tes3reference](../../types/tes3reference)): *Read-only*. The travel marker that marks the destination.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor of the merchant the player is interacting with.
* `price` (number): The adjusted price of travelling.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. mobile’s related reference.

