# tes3creature

A creature object that has not been cloned. Typically represents the raw information edited in the construction set.

This type inherits the following: [tes3actor](../../types/tes3actor), [tes3physicalObject](../../types/tes3physicalObject), [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
## Properties

### `actorFlags`

*Read-only*. A number representing the actor flags. Truly a bit field.

**Returns**:

* `result` (number)

***

### `aiConfig`

*Read-only*. A substructure off of actors that contains information on the current AI configuration.

**Returns**:

* `result` (tes3aiConfig)

***

### `attacks`

A table of three attacks, represented by a trio of tes3rangeInt.

**Returns**:

* `result` (table)

***

### `attributes`

A table of eight numbers, representing the base values for the actor's attributes.

**Returns**:

* `result` (table)

***

### `barterGold`

Friendly access to actor's barter gold amount.

**Returns**:

* `result` (number)

***

### `biped`

Access to the creature's biped flag.

**Returns**:

* `result` (boolean)

***

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `blood`

Friendly access to actor's blood type.

**Returns**:

* `result` (number)

***

### `boundingBox`

The bounding box for the object.

**Returns**:

* `result` ([tes3boundingBox](../../types/tes3boundingBox))

***

### `cloneCount`

*Read-only*. The number of clones that exist of this actor.

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

### `equipment`

*Read-only*. The items currently equipped to the actor.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `fatigue`

*Read-only*. The actor's max fatigue.

**Returns**:

* `result` (number)

***

### `flies`

Access to the creature's flies flag.

**Returns**:

* `result` (boolean)

***

### `health`

*Read-only*. The actor's max health.

**Returns**:

* `result` (number)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `inventory`

*Read-only*. The items currently carried by the actor.

**Returns**:

* `result` ([tes3inventory](../../types/tes3inventory))

***

### `isAttacked`

*Read-only*. If true, the actor's attacked flag is set.

**Returns**:

* `result` (boolean)

***

### `isEssential`

*Read-only*. If true, the actor's essential flag is set.

**Returns**:

* `result` (boolean)

***

### `isInstance`

Always returns false.

**Returns**:

* `result` (boolean)

***

### `isLocationMarker`

True if this object is an editor marker for a gameplay location. These include travel, intervention, prison, door, and interior north markers. Markers are invisible in-game.

**Returns**:

* `result` (boolean)

***

### `isRespawn`

*Read-only*. If true, the actor's respawn flag is set.

**Returns**:

* `result` (boolean)

***

### `level`

*Read-only*. The base level of the creature.

**Returns**:

* `result` (number)

***

### `magicka`

*Read-only*. The actor's max magicka.

**Returns**:

* `result` (number)

***

### `mesh`

The path to the object's mesh.

**Returns**:

* `result` (string)

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

### `previousInCollection`

The previous object in parent collection's list.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

***

### `respawns`

Access to the creature's respawns flag.

**Returns**:

* `result` (boolean)

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

### `script`

The script that runs on the object.

**Returns**:

* `result` (tes3script)

***

### `skills`

A table of three numbers, representing the base values for the creature's combat, magic, and stealth skills.

**Returns**:

* `result` (table)

***

### `soul`

The amount of soul value that the creature provides.

**Returns**:

* `result` (number)

***

### `soundCreature`

A creature to use instead of this one for sound generation.

**Returns**:

* `result` ([tes3creature](../../types/tes3creature))

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

### `spells`

*Read-only*. A list of spells that the actor has access to. It is a tes3spellList, which is a list wrapper with helper functions. The actual list is accessed with .iterator. e.g. for _, spell in pairs(creature.spells.iterator) do print(spell.name) end

**Returns**:

* `result` ([tes3spellList](../../types/tes3spellList))

***

### `stolenList`

A list of actors that the object has been stolen from.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `supportsLuaData`

If true, references of this object can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

***

### `swims`

Access to the creature's swims flag.

**Returns**:

* `result` (boolean)

***

### `type`

The type of the creature, represented by a number for normal, daedra, undead, or humanoid.

**Returns**:

* `result` (number)

***

### `usesEquipment`

Access to the creature's usesEquipment flag.

**Returns**:

* `result` (boolean)

***

### `walks`

Access to the creature's walks flag.

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

### `offersService`

Checks if the actor will offer a service in dialogue. This an offer and may still be refused by dialogue checks. To also get the result of dialogue checks, use tes3.checkMerchantOffersService.

```lua
local result = tes3actor:offersService(service)
```

**Parameters**:

* `service` (number): Use one of the tes3.merchantService.* constants.

**Returns**:

* `result` (boolean)

***

### `onInventoryClose`

A callback function invoked when an inventory is closed. Typically not used outside of specific purposes. You may find tes3.reference's onCloseInventory() to be more convenient to use.

```lua
tes3actor:onInventoryClose(reference)
```

**Parameters**:

* `reference` ([tes3reference](../../types/tes3reference))

***

### `tradesItemType`

Checks if the actor will buy and sell items of a given object type. e.g. actor:tradesItemType(tes3.objectType.repairItem)

```lua
local result = tes3actor:tradesItemType(objectType)
```

**Parameters**:

* `objectType` (tes3objectType): tes3.objectType.* constants can be passed here.

**Returns**:

* `result` (boolean)

***

