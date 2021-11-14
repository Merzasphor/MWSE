# tes3audioController

A controller for audio. It holds data on the status of the current and next music tracks, volume settings and other related facilities. All the volumes are expressed in range [0, 1].

## Properties

### `currentMusicFilePath`

File path of the currently playing music track. The path can not be longer than 260 characters.

**Returns**:

* `result` (string)

***

### `disableAudio`

A flag which controls whether the audio is disabled or not.

**Returns**:

* `result` (boolean)

***

### `listenerPosition`



**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `musicDuration`

*Read-only*. The duration of the currently playing music track.

**Returns**:

* `result` (number)

***

### `musicFadeBeginTimestamp`



**Returns**:

* `result` (number)

***

### `musicNextTrackStartTimestamp`



**Returns**:

* `result` (number)

***

### `musicNextTrackVolume`

The volume of the next track.

**Returns**:

* `result` (number)

***

### `musicPosition`

Current play time for currently playing music track.

**Returns**:

* `result` (number)

***

### `nextMusicFilePath`

File path of the music track which is to be played next. The path can not be longer than 260 characters.

**Returns**:

* `result` (string)

***

### `pitchAxis`

Approximated pitch axis in radians.

**Returns**:

* `result` (number)

***

### `volumeEffects`

Volume of the effects. Corresponds to the effects volume slider in Audio settings.

**Returns**:

* `result` (number)

***

### `volumeFootsteps`

Volume of the footsteps. Corresponds to the footsteps volume slider in Audio settings.

**Returns**:

* `result` (number)

***

### `volumeMaster`

Master volume. Corresponds to the master volume slider in Audio settings.

**Returns**:

* `result` (number)

***

### `volumeMusic`

Volume of the music. Corresponds to the music volume slider in Audio settings.

**Returns**:

* `result` (number)

***

### `volumeVoice`

Volume of the voices. Corresponds to the voice volume slider in Audio settings.

**Returns**:

* `result` (number)

***

### `yawAxis`

Approximated yaw axis in radians.

**Returns**:

* `result` (number)

***

## Methods

### `changeMusicTrack`

Changes currently playing music track according to provided parameters.

```lua
tes3audioController:changeMusicTrack({ filename = ..., crossfade = ..., volume = ... })
```

**Parameters**:

* `params` (table)
	* `filename` (string): File name of the new music track.
	* `crossfade` (number): *Default*: `1000`. Duration of the crossfading between music tracks. Measured in miliseconds.
	* `volume` (number): *Default*: `1`. Allows changing the volume of the music track.

***

### `getMixVolume`

Final volume of a provided type of audio, after master volume and its own volume adjustments. Music volume is an exception since it isn't affected by master volume.

```lua
local volume = tes3audioController:getMixVolume(mix)
```

**Parameters**:

* `mix` (tes3.soundMix.* constants): The type of sound mix to perform a check for.

**Returns**:

* `volume` (number)

***

