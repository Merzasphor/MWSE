# tes3dialogueInfo

A child for a given dialogue. Whereas a dialogue may be a conversation topic, a tes3dialogueInfo would be an individual response.

This type inherits the following: [tes3baseObject](../../types/tes3baseObject)
## Properties

### `actor`

The speaker's actor that the info is filtered for.

**Returns**:

* `result` ([tes3actor](../../types/tes3actor))

***

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `cell`

The speaker's current cell that the info is filtered for.

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

***

### `deleted`

The deleted state of the object.

**Returns**:

* `result` (boolean)

***

### `disabled`

The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `disposition`

The minimum disposition that the info is filtered for.

**Returns**:

* `result` (number)

***

### `firstHeardFrom`

The actor that the player first heard the info from.

**Returns**:

* `result` ([tes3actor](../../types/tes3actor))

***

### `id`

The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `npcClass`

The speaker's class that the info is filtered for.

**Returns**:

* `result` ([tes3class](../../types/tes3class))

***

### `npcFaction`

The speaker's faction that the info is filtered for.

**Returns**:

* `result` ([tes3faction](../../types/tes3faction))

***

### `npcRace`

The speaker's race that the info is filtered for.

**Returns**:

* `result` ([tes3actor](../../types/tes3actor))

***

### `npcRank`

The speaker's faction rank that the info is filtered for.

**Returns**:

* `result` (number)

***

### `npcSex`

The speaker's sex that the info is filtered for.

**Returns**:

* `result` (number)

***

### `objectFlags`

The raw flags of the object.

**Returns**:

* `result` (number)

***

### `objectType`

The type of object. Maps to values in tes3.objectType.

**Returns**:

* `result` (number)

***

### `pcFaction`

The player's joined faction that the info is filtered for.

**Returns**:

* `result` (number)

***

### `pcRank`

The player's rank required rank in the speaker's faction.

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

The filename of the mod that owns this object.

**Returns**:

* `result` (string)

***

### `supportsLuaData`

If true, references of this object can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

***

### `text`

String contents for the info. This is not kept in memory, and must be loaded from files for each call.

**Returns**:

* `result` (string)

***

### `type`

The type of the info.

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

