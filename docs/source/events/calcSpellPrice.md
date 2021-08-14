# calcSpellPrice

This event is called when determining the cost of purchasing a spell. The price can be modified.

```lua
--- @param e calcSpellPriceEventData
local function calcSpellPriceCallback(e)
end
event.register("calcSpellPrice", calcSpellPriceCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `basePrice` (number): *Read-only*. The price before adjustment.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor of the merchant the player is interacting with.
* `price` (number): The adjusted price of spell.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. mobile’s related reference.
* `spell` ([tes3spell](../../types/tes3spell)): *Read-only*. The spell currently being purchased.

