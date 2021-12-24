# tes3enchantment

An enchantment game object.

This type inherits the following: [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
## Properties

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `castType`

The enchantment's cast type. Maps to [`tes3.enchantmentType`](https://mwse.github.io/MWSE/references/enchantment-types/) constants.

**Returns**:

* `result` (number)

***

### `chargeCost`

The cost of using the enchantment.

**Returns**:

* `result` (number)

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

### `effects`

*Read-only*. An array-style table of the [`tes3effect`](https://mwse.github.io/MWSE/types/tes3effect/) data on the object.

**Returns**:

* `result` (table)

***

### `flags`

A bit field for the enchantment's flags.

**Returns**:

* `result` (number)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `isLocationMarker`

True if this object is an editor marker for a gameplay location. These include travel, intervention, prison, door, and interior north markers. Markers are invisible in-game.

**Returns**:

* `result` (boolean)

***

### `maxCharge`

The maximum charge for the associated enchantment.

**Returns**:

* `result` (number)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `nextInCollection`

The next object in parent collection's list.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

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

### `owningCollection`

The collection responsible for holding this object.

**Returns**:

* `result` ([tes3referenceList](../../types/tes3referenceList))

***

### `persistent`

The persistent flag of the object.

**Returns**:

* `result` (boolean)

***

### `previousInCollection`

The previous object in parent collection's list.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

***

### `scale`

The object's scale.

**Returns**:

* `result` (number)

***

### `sceneCollisionRoot`

The scene graph node for this object's physics collision, if its mesh has a root collision node.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneNode`

The scene graph node for this object.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneReference`

The scene graph reference node for this object.

**Returns**:

* `result` ([niNode](../../types/niNode))

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

### `getActiveEffectCount`

Returns the amount of effects the `tes3enchantment` object has.

```lua
local count = tes3enchantment:getActiveEffectCount()
```

**Returns**:

* `count` (number)

***

### `getFirstIndexOfEffect`

Returns the index of a first effect of a given effectId in the parent `tes3enchantment` object.

```lua
local index = tes3enchantment:getFirstIndexOfEffect(effectId)
```

**Parameters**:

* `effectId` (number): The effectId to perform a check for. Maps to [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) constants, including magic effects added with [`tes3.addMagicEffect()`](https://mwse.github.io/MWSE/apis/tes3/#tes3addmagiceffect).

**Returns**:

* `index` (number)

***

## Functions

