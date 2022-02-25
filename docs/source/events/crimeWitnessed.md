# crimeWitnessed

This event fires when a crime is witnessed by an actor.

```lua
--- @param e crimeWitnessedEventData
local function crimeWitnessedCallback(e)
end
event.register(tes3.event.crimeWitnessed, crimeWitnessedCallback)
```

!!! tip
	This event can be filtered based on the **`type`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `position` ([tes3vector3](../../types/tes3vector3)): *Read-only*. The position that the crime ocurred at.
* `realTimestamp` (number): *Read-only*. The timestamp that the crime ocurred at.
* `type` (string): *Read-only*. The type of crime that was committed. The type can be "attack", "killing", "stealing", "pickpocket", "theft", "trespass", and "werewolf". Crime "theft" is raised when picking up owned items. Crime "trespass" is raised when lockpicking, probing or sleeping in owned beds.
* `value` (number): *Read-only*. The bounty value of the crime.
* `victim` ([tes3actor](../../types/tes3actor), [tes3faction](../../types/tes3faction)): *Read-only*. The victim of the crime, as a general actor base object or faction.
* `victimFaction` ([tes3faction](../../types/tes3faction)): *Read-only*. The faction that the crime was against, assuming the victim is, or is in, one.
* `victimMobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile of the victim, if applicable, giving access to the unique victim.
* `witness` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference that witnessed the crime.
* `witnessMobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor of the reference that witnessed the crime.

