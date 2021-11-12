# addTempSound



```lua
--- @param e addTempSoundEventData
local function addTempSoundCallback(e)
end
event.register("addTempSound", addTempSoundCallback)
```

!!! tip
	This event can be filtered based on the **`sound`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `flags` (number): *Read-only*. A flag whether the sound is looping or not. 0 means the sound doesn't loop, 1 means the sound loops.
* `isVoiceover` (boolean): A flag whether the sound is a voiced line, which are usually found in the Sound\Vo data folder.
* `path` (string): The path to the sound to play, relative to Data Files\Sounds
* `pitch` (number): Pitch of the sound.
* `reference` ([tes3reference](../../types/tes3reference)): The reference which is emiting the sound.
* `sound` ([tes3sound](../../types/tes3sound)): 
* `volume` (number): The volume of the sound. Volume = 1 means 100 % loudness. Values lower than 1 make the sound quiter.

