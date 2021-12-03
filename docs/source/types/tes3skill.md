# tes3skill

A skill object.

This type inherits the following: [tes3baseObject](../../types/tes3baseObject)
## Properties

### `actions`

*Read-only*. A table with 4 values. The amount of experience an action (use of skill) awards.

**Returns**:

* `result` (table)

***

### `attribute`

*Read-only*. Skill's governing attribute. Maps to [`tes3.attribute`](https://mwse.github.io/MWSE/references/attributes/) constants.

**Returns**:

* `result` (number)

***

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

### `iconPath`

*Read-only*. The path to the icon for the skill.

**Returns**:

* `result` (string)

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

### `name`

*Read-only*. The player-facing name of the skill.

**Returns**:

* `result` (string)

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

### `specialization`

The specialization in which the skill belongs. Maps to [`tes3.specialization`](https://mwse.github.io/MWSE/references/specialization-types/) constants.

**Returns**:

* `result` (number)

***

### `supportsLuaData`

If true, references of this object can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

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

