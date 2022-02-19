# tes3dialogue

A parent-level dialogue, such as a topic, voice, greeting, persuasion response, or journal.

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

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `info`

*Read-only*. A collection of individual entries in the dialogue.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `journalIndex`

For journal dialogues, the currently active journal index.

**Returns**:

* `result` (number, nil)

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

*Read-only*. The type of object. Maps to values in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/).

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

### `type`

*Read-only*. The type of the dialogue. Maps to values in [`tes3.dialogueType`](https://mwse.github.io/MWSE/references/dialogue-types/) namespace.

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

### `addToJournal`

Adds the dialogue to the player's journal, if applicable, at a given index.

```lua
local result = tes3dialogue:addToJournal({ index = ..., actor = ... })
```

**Parameters**:

* `params` (table)
	* `index` (number): *Default*: `0`.
	* `actor` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): *Default*: `tes3.player`.

**Returns**:

* `result` (boolean)

***

### `getInfo`

Fetches the info that a given actor would produce for the dialogue.

```lua
local result = tes3dialogue:getInfo({ actor = ... })
```

**Parameters**:

* `params` (table)
	* `actor` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string)

**Returns**:

* `result` ([tes3dialogueInfo](../../types/tes3dialogueInfo))

***

### `getJournalInfo`

Retrieves the info object for a journal. By default this will return the info for the player's current journal index for this dialogue. An index can be provided to fetch a specific index's related info.

```lua
local journalInfo = tes3dialogue:getJournalInfo(index)
```

**Parameters**:

* `index` (number): *Optional*. The index of the journal to fetch the info for. If not provided, the current player's journal index is used.

**Returns**:

* `journalInfo` ([tes3dialogueInfo](../../types/tes3dialogueInfo))

***

### `loadQuestName`

This method finds the info that contains the quest name, then loads and returns its text. This method accesses the disk, and may be slow to operate. For dialogues that aren't journal-based, this will be `nil`.

```lua
local questName = tes3dialogue:loadQuestName()
```

**Returns**:

* `questName` (string, nil)

***

