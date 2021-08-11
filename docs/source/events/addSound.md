# addSound

This event is triggered when a sound is player by the game or when tes3.playSound is called. This event can be blocked.

```lua
--- @type e event.addSound
local function addSoundCallback(e)
end
event.register("addSound", addSoundCallback)
```

## Event Data

* `pitch` (number): Pitch of the sound.
* `flags` (number): 
* `sound` ([tes3sound](../../types/tes3sound)): The sound going to be played.
* `volume` (number): The volume of the sound. Volume = 1 means 100 % loudness. Values lower than 1 the sound quiter.
* `isVoiceover` (boolean): 
* `reference` ([tes3reference](../../types/tes3reference)): The reference which is emiting the sound.

