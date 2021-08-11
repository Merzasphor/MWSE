# calcTrainingPrice

This event is called when determining the cost of training, and can be used to modify the given price.

```lua
--- @param e calcTrainingPriceEventData
local function calcTrainingPriceCallback(e)
end
event.register("calcTrainingPrice", calcTrainingPriceCallback)
```

## Event Data

* `price` (number): The adjusted price of the training.
* `skillId` (number): The ID of the skill to be trained.
* `reference` ([tes3reference](../../types/tes3reference)): mobile’s related reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor of the trainer the player is interacting with.
* `basePrice` (number): The price before adjustment.
* `skill` ([tes3statisticSkill](../../types/tes3statisticSkill)): The ID of the skill to be trained.

