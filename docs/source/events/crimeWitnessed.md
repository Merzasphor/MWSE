# crimeWitnessed

This event fires when a crime is witnessed by an actor.

```lua
--- @param e crimeWitnessedEventData
local function crimeWitnessedCallback(e)
end
event.register("crimeWitnessed", crimeWitnessedCallback)
```

!!! tip
	This event can be filtered based on the **`type`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `position` ([tes3vector3](../../types/tes3vector3)): *Read-only*. The position that the crime ocurred at.
* `realTimestamp` (number): *Read-only*. The timestamp that the crime ocurred at.
* `type` (string): *Read-only*. The type of crime that was committed.
* `value` (number): *Read-only*. The bounty value of the crime.
* `witness` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference that witnessed the crime.
* `witnessMobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor of the reference that witnessed the crime.

