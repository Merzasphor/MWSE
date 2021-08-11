--- @meta

--- This event is called when determining the cost of purchasing a spell. The price can be modified.
--- @class calcSpellPriceEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field price number The adjusted price of spell.
--- @field reference tes3reference mobile’s related reference.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor of the merchant the player is interacting with.
--- @field basePrice number The price before adjustment.
--- @field spell tes3spell The spell currently being purchased.
