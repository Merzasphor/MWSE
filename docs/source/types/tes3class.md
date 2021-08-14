# tes3class

A core object representing a character class.

This type inherits the following: [tes3baseObject](../../types/tes3baseObject)
## Properties

### `attributes`

*Read-only*. An array-style table of the two attribute IDs associated with the class.

**Returns**:

* `result` (table)

***

### `bartersAlchemy`

If true, the class will barter alchemy items.

**Returns**:

* `result` (boolean)

***

### `bartersApparatus`

If true, the class will barter apparatus items.

**Returns**:

* `result` (boolean)

***

### `bartersArmor`

If true, the class will barter armor items.

**Returns**:

* `result` (boolean)

***

### `bartersBooks`

If true, the class will barter book items.

**Returns**:

* `result` (boolean)

***

### `bartersClothing`

If true, the class will barter clothing items.

**Returns**:

* `result` (boolean)

***

### `bartersEnchantedItems`

If true, the class will barter enchanted items.

**Returns**:

* `result` (boolean)

***

### `bartersIngredients`

If true, the class will barter ingredient items.

**Returns**:

* `result` (boolean)

***

### `bartersLights`

If true, the class will barter light items.

**Returns**:

* `result` (boolean)

***

### `bartersLockpicks`

If true, the class will barter lockpick items.

**Returns**:

* `result` (boolean)

***

### `bartersMiscItems`

If true, the class will barter misc items.

**Returns**:

* `result` (boolean)

***

### `bartersProbes`

If true, the class will barter probe items.

**Returns**:

* `result` (boolean)

***

### `bartersRepairTools`

If true, the class will barter repair items.

**Returns**:

* `result` (boolean)

***

### `bartersWeapons`

If true, the class will barter weapon items.

**Returns**:

* `result` (boolean)

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

### `description`

Loads from disk and returns the description of the class.

**Returns**:

* `result` (string)

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

### `majorSkills`

*Read-only*. An array-style table of the 5 skills IDs associated with the class' major skills.

**Returns**:

* `result` (table)

***

### `minorSkills`

*Read-only*. An array-style table of the 5 skills IDs associated with the class' major skills.

**Returns**:

* `result` (table)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `name`

The player-facing name for the object.

**Returns**:

* `result` (string)

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

### `offersEnchanting`

If true, the class will offer repair services.

**Returns**:

* `result` (boolean)

***

### `offersRepairs`

If true, the class will offer enchanting services.

**Returns**:

* `result` (boolean)

***

### `offersSpellmaking`

If true, the class will offer spellmaking services.

**Returns**:

* `result` (boolean)

***

### `offersSpells`

If true, the class will offer spell selling services.

**Returns**:

* `result` (boolean)

***

### `offersTraining`

If true, the class will offer spell training services.

**Returns**:

* `result` (boolean)

***

### `persistent`

The persistent flag of the object.

**Returns**:

* `result` (boolean)

***

### `playable`

If true, the class is selectable at character generation.

**Returns**:

* `result` (boolean)

***

### `services`

The services offered by the class. This is a bit field, and its values should typically be accessed through values such as bartersAlchemy.

**Returns**:

* `result` (number)

***

### `skills`

*Read-only*. An array-style table of the 10 skills IDs associated with the class. For major or minor skills specifically, use the majorSkills and MinorSkills properties.

**Returns**:

* `result` (table)

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

The specialization for the class. Maps to the tes3.specialization table.

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

