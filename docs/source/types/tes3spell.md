# tes3spell

A spell game object.

This type inherits the following: [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
## Properties

### `alwaysSucceeds`

A flag that determines if casting the spell will always succeed.

**Returns**:

* `result` (boolean)

***

### `autoCalc`

Determines if the magicka cost for the spell is autocalculated, and if the spell may be automatically assigned to NPCs if they are skillful enough to cast it.

**Returns**:

* `result` (boolean)

***

### `basePurchaseCost`

Calculates the base cost to purchase the spell. This value is not adjusted by mercantile skills.

**Returns**:

* `result` (number)

***

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `castType`

The spell's cast type.

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

*Read-only*. An array-style table of the tes3effect data on the object.

**Returns**:

* `result` (table)

***

### `flags`

A bit field for the spell's flags.

**Returns**:

* `result` (number)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `isActiveCast`

*Read-only*. True if the spell is actively cast. If false, the spell's effects are always passively affecting the owner.

**Returns**:

* `result` (boolean)

***

### `isLocationMarker`

True if this object is an editor marker for a gameplay location. These include travel, intervention, prison, door, and interior north markers. Markers are invisible in-game.

**Returns**:

* `result` (boolean)

***

### `magickaCost`

No description yet available.

**Returns**:

* `result` (number)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `name`

The name of the spell.

**Returns**:

* `result` (string)

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

*Read-only*. The type of object. Maps to values in tes3.objectType.

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

### `playerStart`

A flag that determines if the spell may be assigned to the player at character generation if the player has enough skill to cast it.

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

### `calculateCastChance`

Calculates the chance that a caster can cast a given spell.

```lua
local result = tes3spell:calculateCastChance({ checkMagicka = ..., caster = ... })
```

**Parameters**:

* `params` (table)
	* `checkMagicka` (boolean): *Optional*. Determines if the caster's magicka should be taken into account during the calculation.
	* `caster` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor)): The caster to perform the calculation against.

**Returns**:

* `result` (number)

***

### `getActiveEffectCount`

Gets the number of active effects in the spell effect table.

```lua
local result = tes3spell:getActiveEffectCount()
```

**Returns**:

* `result` (number)

***

### `getFirstIndexOfEffect`

Gets the first index of an effect ID in the spell effect table.

```lua
local result = tes3spell:getFirstIndexOfEffect(effectId)
```

**Parameters**:

* `effectId` (number): The tes3effect ID to look for.

**Returns**:

* `result` (number)

***

### `getLeastProficientEffect`

Returns the effect of the spell that a given actor is least proficient with.

```lua
local effect = tes3spell:getLeastProficientEffect(actor)
```

**Parameters**:

* `actor` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), [tes3npc](../../types/tes3npc), [tes3npcInstance](../../types/tes3npcInstance)): The actor to calculate for. A mobile actor is preferred, as passing only a tes3npc will not use up to date skill information.

**Returns**:

* `effect` ([tes3effect](../../types/tes3effect), nil): The least proficient effect, or nil if the spell has no valid effects.

***

### `getLeastProficientSchool`

Returns the school of the least proficient effect on the spell, for a given actor.

```lua
local schoolID = tes3spell:getLeastProficientSchool(actor)
```

**Parameters**:

* `actor` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), [tes3npc](../../types/tes3npc), [tes3npcInstance](../../types/tes3npcInstance)): The actor to calculate for. A mobile actor is preferred, as passing only a tes3npc will not use up to date skill information.

**Returns**:

* `schoolID` (number, nil): The least proficient school ID, or nil if the spell has no valid effects.

***

## Functions

