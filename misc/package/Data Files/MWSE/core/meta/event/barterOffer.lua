--- @meta

--- This event is called when a potentially successful barter offer is made by the player. Potentially successful means both parties have the required funds to make the trade.
--- @class barterOfferEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field buying table Table of tes3what being bought. These items will be transfered to player's inventory on a successful bartering event.
--- @field value number Total value in gold of items being traded.
--- @field offer number Offered gold amount.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor of the merchant the player is interacting with.
--- @field selling table Table of tes3what being sold. These items will be transfered to bartender's inventory on a successful bartering event.
--- @field success boolean Whether the trade was accepted or not.
barterOffer = {}

