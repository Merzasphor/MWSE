# tes3race

A core object representing a character race.

This type inherits the following: [tes3baseObject](../../types/tes3baseObject)
## Properties

### `abilities`

A list of abilities that NPCs of that race have access to. It is a tes3spellList, which is a list wrapper with helper functions. The actual list is accessed with .iterator. e.g. for _, ability in pairs(race.abilities.iterator) do print(ability.name) end

**Returns**:

* `result` ([tes3spellList](../../types/tes3spellList))

***

### `baseAttributes`

Array-style table access to base 8 attributes for the race. Each element in the array is a tes3raceBaseAttribute.

**Returns**:

* `result` (table)

***

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

### `description`

Loads from disk and returns the description of the race.

**Returns**:

* `result` (string)

***

### `disabled`

The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `femaleBody`

Access to all the body parts that will be used for female actors of this race.

**Returns**:

* `result` ([tes3raceBodyParts](../../types/tes3raceBodyParts))

***

### `flags`

Raw bit-based flags.

**Returns**:

* `result` (number)

***

### `height`

Access to the the height pair for males/females of the race.

**Returns**:

* `result` ([tes3raceHeightWeight](../../types/tes3raceHeightWeight))

***

### `id`

The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `isBeast`

Access to the beast race flag.

**Returns**:

* `result` (boolean)

***

### `isPlayable`

Access to the playable race flag.

**Returns**:

* `result` (boolean)

***

### `maleBody`

Access to all the body parts that will be used for male actors of this race.

**Returns**:

* `result` ([tes3raceBodyParts](../../types/tes3raceBodyParts))

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

### `skillBonuses`

Array-style table access for 7 skill bonuses for the race. Each element in the array is a tes3raceSkillBonus.

**Returns**:

* `result` (table)

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

### `weight`

Access to the the height pair for males/females of the race.

**Returns**:

* `result` ([tes3raceHeightWeight](../../types/tes3raceHeightWeight))

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

