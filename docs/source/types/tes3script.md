# tes3script

A script object.

This type inherits the following: [tes3baseObject](../../types/tes3baseObject)
## Properties

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `context`

*Read-only*. A special context used for getting and setting script's variables.

**Returns**:

* `result` ([tes3scriptContext](../../types/tes3scriptContext))

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

### `floatVariableCount`

*Read-only*. The number of variables of float type in the script.

**Returns**:

* `result` (number)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `longVariableCount`

*Read-only*. The number of variables of long type in the script.

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

*Read-only*. The type of object. Maps to values in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/).

**Returns**:

* `result` (number)

***

### `persistent`

The persistent flag of the object.

**Returns**:

* `result` (boolean)

***

### `shortVariableCount`

*Read-only*. The number of variables of short type in the script.

**Returns**:

* `result` (number)

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

## Methods

### `__tojson`

Serializes the object to json.

```lua
local string = tes3baseObject:__tojson()
```

**Returns**:

* `string` (string)

***

### `getVariableData`

This method fetches all of the script's variables as a table.

```lua
local results = tes3script:getVariableData()
```

**Returns**:

* `results` (table): The table with all of script's variable names as keys. Each entry has the following fields:
	1. type - `s`, `f` or `l`, which stand for `short`, `float`, and `long`
	2. index - the order of occurrence of the variable in the script, starting from `0`
	3. value - this can have `nil` value

***

