# tes3container

A container object that has not been cloned. Typically represents the raw information edited in the construction set.

This type inherits the following: [tes3actor](../../types/tes3actor), [tes3physicalObject](../../types/tes3physicalObject), [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
## Properties

### `actorFlags`

*Read-only*. A number representing the actor flags. Truly a bit field.

**Returns**:

* `result` (number)

***

### `barterGold`

Friendly access to actor's barter gold amount.

**Returns**:

* `result` (number)

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

### `capacity`

The amount of weight that the container can hold.

**Returns**:

* `result` (number)

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

*Read-only*. The type of object. Maps to values in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/).

**Returns**:

* `result` (number)

***

### `organic`

Determines if the container's organic flag is enabled.

**Returns**:

* `result` (boolean)

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

Determines if the container's respawn flag is enabled.

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

* `result` ([tes3script](../../types/tes3script))

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

## Methods

### `__tojson`

Serializes the object to json.

```lua
local string = tes3baseObject:__tojson()
```

**Returns**:

* `string` (string)

***

### `hasItemEquipped`

Checks if the actor has provided item equipped.

```lua
local result = tes3actor:hasItemEquipped({ item = ..., itemData = ... })
```

**Parameters**:

* `params` (table)
	* `item` ([tes3item](../../types/tes3item), string): The item to perform a check for.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*.

**Returns**:

* `result` (boolean)

***

### `offersService`

Checks if the actor will offer a service in dialogue. This an offer and may still be refused by dialogue checks. To also get the result of dialogue checks, use [`tes3.checkMerchantOffersService()`](https://mwse.github.io/MWSE/apis/tes3/#tes3checkmerchantoffersservice).

```lua
local result = tes3actor:offersService(service)
```

**Parameters**:

* `service` (number): Use one of the [`tes3.merchantService.*`](https://mwse.github.io/MWSE/references/merchant-service-types/) constants.

**Returns**:

* `result` (boolean)

***

### `onInventoryClose`

A callback function invoked when an inventory is closed. Typically not used outside of specific purposes. You may find `tes3.reference`'s `onCloseInventory()` to be more convenient to use.

```lua
tes3actor:onInventoryClose(reference)
```

**Parameters**:

* `reference` ([tes3reference](../../types/tes3reference))

***

### `tradesItemType`

Checks if the actor will buy and sell items of a given object type. e.g. `actor:tradesItemType(tes3.objectType.repairItem)`

```lua
local result = tes3actor:tradesItemType(objectType)
```

**Parameters**:

* `objectType` (number): Accepts values from [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) namespace.

**Returns**:

* `result` (boolean)

***

