# tes3dialogueInfo

A child for a given dialogue. Whereas a dialogue may be a conversation topic, a `tes3dialogueInfo` would be an individual response.

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

The minimum disposition that the info is filtered for. For journal-based dialogues, this is the same as the `journalIndex` property, which should be used instead.

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

### `isQuestFinished`

Quick access to the "quest finished" flag. For dialogues that aren't journal-based, this will be `nil`.

**Returns**:

* `result` (boolean, nil)

***

### `isQuestName`

Quick access to the "quest name" flag. If this is true, this info contains the name of the quest. For dialogues that aren't journal-based, this will be `nil`.

**Returns**:

* `result` (boolean, nil)

***

### `isQuestRestart`

Quick access to the "quest restart" flag. For dialogues that aren't journal-based, this will be `nil`.

**Returns**:

* `result` (boolean, nil)

***

### `journalIndex`

The current index for the quest. For dialogues that aren't journal-based, this will be `nil`.

**Returns**:

* `result` (number, nil)

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

*Read-only*. The type of object. Maps to values in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/).

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

*Read-only*. The type of the info. Maps to values in [`tes3.dialogueType`](https://mwse.github.io/MWSE/references/dialogue-types/) namespace.

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

This method filters the associated dialogue info for given arguments and returns true if the dialogue info filtering passes. This method rises [`infoFilter`](https://mwse.github.io/MWSE/events/infoFilter/) event.

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

