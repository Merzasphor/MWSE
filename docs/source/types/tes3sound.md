# tes3sound

A sound object created in the TES3 CS.

This type inherits the following: [tes3baseObject](../../types/tes3baseObject)
## Properties

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `deleted`

*Read-only*. The deleted state of the object.

**Returns**:

* `result` (boolean)

***

### `disabled`

*Read-only*. The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `filename`

*Read-only*. Path to the sound file.

**Returns**:

* `result` (string)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `maxDistance`

The maximum distance the sound will be played at. Defaults to 0. If both this and minDistance are 0, the values are ignored.

**Returns**:

* `result` (number)

***

### `minDistance`

The minimum distance the sound will be played at. Defaults to 0.

**Returns**:

* `result` (number)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `objectFlags`

*Read-only*. The raw flags of the object.

**Returns**:

* `result` (number)

***

### `objectType`

*Read-only*. The type of object. Maps to values in tes3.objectType.

**Returns**:

* `result` (number)

***

### `persistent`

The persistent flag of the object.

**Returns**:

* `result` (boolean)

***

### `sourceless`

The soruceless flag of the object.

**Returns**:

* `result` (boolean)

***

### `sourceMod`

*Read-only*. The filename of the mod that owns this object.

**Returns**:

* `result` (string)

***

### `supportsLuaData`

If true, references of this object can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

***

### `volume`

Direct access to sound's volume.

**Returns**:

* `result` (number)

***

## Methods

### `__tojson`

Serializes the object to json.

```lua
local result = tes3sound:__tojson()
```

**Returns**:

* `result` (string)

***

### `isLooping`

Returns true if the sound is actively looping.

```lua
local result = tes3sound:isLooping()
```

**Returns**:

* `result` (boolean)

***

### `isPlaying`

Returns true if the sound is actively playing.

```lua
local result = tes3sound:isPlaying()
```

**Returns**:

* `result` (boolean)

***

### `play`

This metod plays the sound.

```lua
tes3sound:play(playbackFlags, volume, pitch, isNot3D)
```

**Parameters**:

* `playbackFlags` (number): *Optional*. These match low-level DirectSound flags. Most mods don't need to modify this, though a value of 1 to loop may be useful. The rest of the flags can be read in the IDirectSoundBuffer8::Play documentation: https://docs.microsoft.com/en-us/previous-versions/windows/desktop/ee418074(v=vs.85).
* `volume` (number): *Optional*.
* `pitch` (number): *Optional*.
* `isNot3D` (boolean): *Optional*.

***

### `stop`

This stops playing the sound.

```lua
tes3sound:stop()
```

***

