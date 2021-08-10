# calcSpellPrice

This event is called when determining the cost of purchasing a spell. The price can be modified.

```lua
--- @type e event.calcSpellPrice
local function calcSpellPriceCallback(e)
end
event.register("calcSpellPrice", calcSpellPriceCallback)
```

## Event Data

* `price` (number): The adjusted price of spell.
* `reference` ([tes3reference](../../types/tes3reference)): mobile’s related reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor of the merchant the player is interacting with.
* `basePrice` (number): The price before adjustment.
* `spell` ([tes3spell](../../types/tes3spell)): The spell currently being purchased.

