# barterOffer

This event is called when a potentially successful barter offer is made by the player. Potentially successful means both parties have the required funds to make the trade.

```lua
--- @param e barterOfferEventData
local function barterOfferCallback(e)
end
event.register("barterOffer", barterOfferCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `buying` (table): *Read-only*. Table of tes3inventoryTile objects being bought. These items will be transfered to player's inventory on a successful bartering event.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor of the merchant the player is interacting with.
* `offer` (number): *Read-only*. Offered gold amount.
* `selling` (table): *Read-only*. Table of tes3inventoryTile objects being sold. These items will be transfered to bartender's inventory on a successful bartering event.
* `success` (boolean): Whether the trade was accepted or not.
* `value` (number): *Read-only*. Total value in gold of items being traded. Negative means the player owes coin, positive means the player gets coin.

