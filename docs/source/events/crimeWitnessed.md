# crimeWitnessed

This event fires when a crime is witnessed by an actor.

```lua
--- @param e crimeWitnessedEventData
local function crimeWitnessedCallback(e)
end
event.register("crimeWitnessed", crimeWitnessedCallback)
```

This event can be filtered based on the **`type`** event data.

## Event Data

* `position` (tes3vector): The position that the crime ocurred at.
* `value` (number): The bounty value of the crime.
* `type` (string): The type of crime that was committed.
* `witnessMobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor of the reference that witnessed the crime.
* `witness` ([tes3reference](../../types/tes3reference)): The reference that witnessed the crime.
* `realTimestamp` (number): The timestamp that the crime ocurred at.

