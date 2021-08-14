# calcTrainingPrice

This event is called when determining the cost of training, and can be used to modify the given price.

```lua
--- @param e calcTrainingPriceEventData
local function calcTrainingPriceCallback(e)
end
event.register("calcTrainingPrice", calcTrainingPriceCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `basePrice` (number): *Read-only*. The price before adjustment.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor of the trainer the player is interacting with.
* `price` (number): The adjusted price of the training.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. mobile’s related reference.
* `skill` ([tes3statisticSkill](../../types/tes3statisticSkill)): *Read-only*. The ID of the skill to be trained.
* `skillId` (number): *Read-only*. The ID of the skill to be trained.

