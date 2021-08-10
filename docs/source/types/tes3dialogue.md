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

The deleted state of the object.

**Returns**:

* `result` (boolean)

***

### `disabled`

The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `id`

The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `info`

A collection of individual entries in the dialogue.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `journalIndex`

For journal dialogues, the currently active journal index.

**Returns**:

* `result` (number)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

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

### `type`

The type of the dialogue.

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
	* `index` (number)
	* `actor` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string)

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

