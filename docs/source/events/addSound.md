# addSound

This event is triggered when a sound is played by the game or when `tes3.playSound()` is called.

```lua
--- @param e addSoundEventData
local function addSoundCallback(e)
end
event.register(tes3.event.addSound, addSoundCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `flags` (number): *Read-only*. A flag whether the sound is looping or not. 0 means the sound doesn't loop, 1 means the sound loops.
* `isVoiceover` (boolean): A flag whether the sound is a voiced line, which are usually found in the Sound\Vo data folder.
* `pitch` (number): Pitch of the sound.
* `reference` ([tes3reference](../../types/tes3reference)): The reference which is emiting the sound.
* `sound` ([tes3sound](../../types/tes3sound)): The sound going to be played.
* `volume` (number): The volume of the sound. Volume = 1 means 100 % loudness. Values lower than 1 make the sound quiter.

