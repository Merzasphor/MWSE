# musicSelectTrack

The musicSelectTrack event occurs when new music is needed after a playing music track ends, or the combat situation changes. It allows you to select your own music for the current conditions by setting eventData.music. However, it does not control transitions to combat music, which in the future will be available in another event.

```lua
--- @param e musicSelectTrackEventData
local function musicSelectTrackCallback(e)
end
event.register("musicSelectTrack", musicSelectTrackCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `music` (string): *Optional*. If set to the path of a given track (relative to Data Files/music), it will play the given path instead of a random one.
* `situation` (number): *Read-only*. Maps to tes3.musicSituation.*, indicating combat or non-combat music.

