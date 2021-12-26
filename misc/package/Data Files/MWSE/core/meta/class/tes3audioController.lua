--- @meta

--- A controller for audio. It holds data on the status of the current and next music tracks, volume settings and other related facilities. All the volumes are expressed in range [0, 1].
--- @class tes3audioController
--- @field currentMusicFilePath string File path of the currently playing music track. The path can not be longer than 260 characters.
--- @field disableAudio boolean A flag which controls whether the audio is disabled or not.
--- @field listenerPosition tes3vector3 
--- @field musicDuration number *Read-only*. The duration of the currently playing music track.
--- @field musicFadeBeginTimestamp number 
--- @field musicNextTrackStartTimestamp number 
--- @field musicNextTrackVolume number The volume of the next track.
--- @field musicPosition number Current play time for currently playing music track.
--- @field nextMusicFilePath string File path of the music track which is to be played next. The path can not be longer than 260 characters.
--- @field pitchAxis number Approximated pitch axis in radians.
--- @field volumeEffects number Volume of the effects. Corresponds to the effects volume slider in Audio settings.
--- @field volumeFootsteps number Volume of the footsteps. Corresponds to the footsteps volume slider in Audio settings.
--- @field volumeMaster number Master volume. Corresponds to the master volume slider in Audio settings.
--- @field volumeMusic number Volume of the music. Corresponds to the music volume slider in Audio settings.
--- @field volumeVoice number Volume of the voices. Corresponds to the voice volume slider in Audio settings.
--- @field yawAxis number Approximated yaw axis in radians.
tes3audioController = {}

--- Changes currently playing music track according to provided parameters.
--- @param params tes3audioController.changeMusicTrack.params This table accepts the following values:
--- 
--- `filename`: string — File name of the new music track.
--- 
--- `crossfade`: number — *Default*: `1000`. Duration of the crossfading between music tracks. Measured in miliseconds.
--- 
--- `volume`: number — *Default*: `1`. Allows changing the volume of the music track.
function tes3audioController:changeMusicTrack(params) end

---Table parameter definitions for `tes3audioController.changeMusicTrack`.
--- @class tes3audioController.changeMusicTrack.params
--- @field filename string File name of the new music track.
--- @field crossfade number *Default*: `1000`. Duration of the crossfading between music tracks. Measured in miliseconds.
--- @field volume number *Default*: `1`. Allows changing the volume of the music track.

--- Final volume of a provided type of audio, after master volume and its own volume adjustments. Music volume is an exception since it isn't affected by master volume.
--- @param mix number The type of sound mix to perform a check for. Accepts values from [`tes3.soundMix`](https://mwse.github.io/MWSE/references/sound-mix-types/) namespace.
--- @return number volume No description yet available.
function tes3audioController:getMixVolume(mix) end

