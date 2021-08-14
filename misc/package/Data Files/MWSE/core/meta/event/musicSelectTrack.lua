--- @meta

--- The musicSelectTrack event occurs when new music is needed after a playing music track ends, or the combat situation changes. It allows you to select your own music for the current conditions by setting eventData.music. However, it does not control transitions to combat music, which in the future will be available in another event.
--- @class musicSelectTrackEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field music string *Optional*. If set to the path of a given track (relative to Data Files/music), it will play the given path instead of a random one.
--- @field situation number *Read-only*. Maps to tes3.musicSituation.*, indicating combat or non-combat music.
