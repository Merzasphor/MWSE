# tes3dialogueInfo

A child for a given dialogue. Whereas a dialogue may be a conversation topic, a tes3dialogueInfo would be an individual response.

This type inherits the following: [tes3baseObject](../../types/tes3baseObject)
## Properties

### `actor`

*Read-only*. The speaker's actor that the info is filtered for.

**Returns**:

* `result` ([tes3actor](../../types/tes3actor))

***

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `cell`

*Read-only*. The speaker's current cell that the info is filtered for.

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

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

### `disposition`

*Read-only*. The minimum disposition that the info is filtered for.

**Returns**:

* `result` (number)

***

### `firstHeardFrom`

The actor that the player first heard the info from.

**Returns**:

* `result` ([tes3actor](../../types/tes3actor))

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `npcClass`

*Read-only*. The speaker's class that the info is filtered for.

**Returns**:

* `result` ([tes3class](../../types/tes3class))

***

### `npcFaction`

*Read-only*. The speaker's faction that the info is filtered for.

**Returns**:

* `result` ([tes3faction](../../types/tes3faction))

***

### `npcRace`

*Read-only*. The speaker's race that the info is filtered for.

**Returns**:

* `result` ([tes3actor](../../types/tes3actor))

***

### `npcRank`

*Read-only*. The speaker's faction rank that the info is filtered for.

**Returns**:

* `result` (number)

***

### `npcSex`

*Read-only*. The speaker's sex that the info is filtered for.

**Returns**:

* `result` (number)

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

### `pcFaction`

*Read-only*. The player's joined faction that the info is filtered for.

**Returns**:

* `result` (number)

***

### `pcRank`

*Read-only*. The player's rank required rank in the speaker's faction.

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

### `text`

*Read-only*. String contents for the info. This is not kept in memory, and must be loaded from files for each call.

**Returns**:

* `result` (string)

***

### `type`

*Read-only*. The type of the info.

**Returns**:

* `result` (number)

***

## Methods

### `__tojson`

Serializes the object to json.

```lua
local string = tes3baseObject:__tojson()
```

**Returns**:

* `string` (string)

***

### `filter`

This method filters the associated dialogue info for given arguments and returns true if the dialogue info filtering passes. This method rises infoFilter event.

```lua
local result = tes3dialogueInfo:filter(actor, reference, source, dialogue)
```

**Parameters**:

* `actor` ([tes3object](../../types/tes3object))
* `reference` ([tes3reference](../../types/tes3reference))
* `source` (number)
* `dialogue` ([tes3dialogue](../../types/tes3dialogue))

**Returns**:

* `result` (boolean)

***

### `runScript`

This method runs the dialogue info's associated script on a given reference.

```lua
tes3dialogueInfo:runScript(reference)
```

**Parameters**:

* `reference` ([tes3reference](../../types/tes3reference)): The reference on which to run the script on.

***

