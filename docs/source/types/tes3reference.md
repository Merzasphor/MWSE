# tes3reference

A reference is a sort of container structure for objects. It holds a base object, as well as various variables associated with that object that make it unique.

For example, many doors may share the same base object. However, each door reference might have a different owner, different lock/trap statuses, etc. that make the object unique.

This type inherits the following: [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
## Properties

### `activationReference`

The current reference, if any, that this reference will activate.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `attachments`

*Read-only*. A table with friendly named access to all supported attachments.

**Returns**:

* `result` (table)

***

### `baseObject`

*Read-only*. This is similar to the object field, but is guaranteed to provide the base-most object. If object is an actor clone, the base actor will be given instead.

**Returns**:

* `result` ([tes3physicalObject](../../types/tes3physicalObject))

***

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `bodyPartManager`

*Read-only*. Access to the reference's body part manager, if available. Typically this is only available on NPC references.

**Returns**:

* `result` (tes3bodyPartManager, nil)

***

### `cell`

*Read-only*. The cell that the reference is currently in.

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

***

### `context`

*Read-only*. Access to the script context for this reference and its associated script.

**Returns**:

* `result` ([tes3scriptContext](../../types/tes3scriptContext))

***

### `data`

A generic lua table that data can be written to, and synced to/from the save. All information stored must be valid for serialization to json. For item references, this is the same table as on the tes3itemData structure. To store data that doesn't get serialized to/from the save, use tempData.

**Returns**:

* `result` (table)

***

### `deleted`

*Read-only*. The deleted state of the object.

**Returns**:

* `result` (boolean)

***

### `destination`

*Read-only*. Returns the travel destination node for this reference, or nil. This can be used to determine where a given door links to.

**Returns**:

* `result` ([tes3travelDestinationNode](../../types/tes3travelDestinationNode), nil)

***

### `disabled`

*Read-only*. The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `facing`

Convenient access to the z-component of the reference's orientation. Setting the facing sets the reference as modified.

**Returns**:

* `result` (number)

***

### `hasNoCollision`

Sets the no-collision flag on this reference, and recalculates collision groups. Use the setNoCollisionFlag function to manage collision group recalculation instead.

**Returns**:

* `result` (boolean)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `isDead`

*Read-only*. Returns true if the object is dead, false if they are alive, or nil if that couldn't be determined.

**Returns**:

* `result` (boolean, nil)

***

### `isEmpty`

Friendly access onto the reference's empty inventory flag.

**Returns**:

* `result` (boolean)

***

### `isLeveledSpawn`

*Read-only*. If true, this reference was created as a result of a leveled spawn.

**Returns**:

* `result` (boolean)

***

### `isLocationMarker`

True if this object is an editor marker for a gameplay location. These include travel, intervention, prison, door, and interior north markers. Markers are invisible in-game.

**Returns**:

* `result` (boolean)

***

### `isRespawn`

*Read-only*. If true, the references respawn flag is set.

**Returns**:

* `result` (boolean)

***

### `itemData`

Gets or sets the attached itemData for this reference. If set to nil, the item data will be unhooked but not deleted.

**Returns**:

* `result` ([tes3itemData](../../types/tes3itemData))

***

### `leveledBaseReference`

*Read-only*. If this reference is a leveled spawn, this is the leveled creature spawn reference. If this reference wasn't the result of a leveled spawn, the value is nil.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference), nil)

***

### `light`

*Read-only*. Direct access to the scene graph light, if a dynamic light is set.

**Returns**:

* `result` ([niPointLight](../../types/niPointLight))

***

### `lockNode`

*Read-only*. Quick access to the reference's lock node, if any.

**Returns**:

* `result` ([tes3lockNode](../../types/tes3lockNode))

***

### `mesh`

The path to the object's mesh.

**Returns**:

* `result` (string)

***

### `mobile`

*Read-only*. Access to the attached mobile object, if applicable.

**Returns**:

* `result` ([tes3mobileCreature](../../types/tes3mobileCreature), [tes3mobileNPC](../../types/tes3mobileNPC), [tes3mobilePlayer](../../types/tes3mobilePlayer), [tes3mobileProjectile](../../types/tes3mobileProjectile), tes3mobileSpell, nil)

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

### `nextNode`

*Read-only*. The next reference in the parent reference list.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `nodeData`

*Read-only*. Redundant access to this object, for iterating over a tes3referenceList.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `object`

*Read-only*. The object that the reference is for, such as a weapon, armor, or actor.

**Returns**:

* `result` ([tes3physicalObject](../../types/tes3physicalObject))

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

### `orientation`

Access to the reference's orientation. Setting the orientation sets the reference as modified.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

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

### `position`

Access to the reference's position. Setting the position sets the reference as modified.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `previousInCollection`

The previous object in parent collection's list.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

***

### `previousNode`

*Read-only*. The previous reference in the parent reference list.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

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

*Read-only*. The scene graph node that the reference uses for rendering.

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

### `stackSize`

Access to the size of a stack, if the reference represents one or more items.

**Returns**:

* `result` (number)

***

### `supportsLuaData`

If true, this reference can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

***

### `tempData`

As with the data field, a generic lua table that data can be written to. No information in this table will persist into saves. For item references, this is the same table as on the tes3itemData structure.

**Returns**:

* `result` (table)

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

### `activate`

Causes this reference to activate another. This will lead them to go through doors, pick up items, etc.

```lua
tes3reference:activate(reference)
```

**Parameters**:

* `reference` ([tes3reference](../../types/tes3reference)): The other reference to activate.

***

### `clearActionFlag`

Unsets a bit in the reference's action data attachment

```lua
tes3reference:clearActionFlag(flagIndex)
```

**Parameters**:

* `flagIndex` (number): The action flag to clear.

***

### `clone`

Clones a reference for a base actor into a reference to an instance of that actor. For example, this will force a container to resolve its leveled items and have its own unique inventory.

```lua
local result = tes3reference:clone()
```

**Returns**:

* `result` (boolean)

***

### `delete`

Disables the reference, removes all its attachments, resets its scale, and sets the reference to be deleted.

```lua
tes3reference:delete()
```

***

### `deleteDynamicLightAttachment`

Deletes the dynamic light attachment, if it exists. This will automatically detach the dynamic light from affected nodes.

```lua
tes3reference:deleteDynamicLightAttachment(removeLightFromParent)
```

**Parameters**:

* `removeLightFromParent` (boolean): *Default*: `false`. If true, the dynamic light is removed from its parent node as well.

***

### `detachDynamicLightFromAffectedNodes`

Removes the dynamic light from any affected scene graph nodes, but will not delete the associated attachment.

```lua
tes3reference:detachDynamicLightFromAffectedNodes()
```

***

### `disable`

Hides the reference, detaches all dynamic lights and sounds, and stops any mobile simulation. Sets the reference as modified implicitly.

```lua
local success = tes3reference:disable()
```

**Returns**:

* `success` (boolean): If true, the reference was successfully disabled.

***

### `enable`

Shows the reference, reattaches all dynamic lights and sounds, and restarts any mobile simulation if the player is close enough. Sets the reference as modified implicitly.

```lua
local success = tes3reference:enable()
```

**Returns**:

* `success` (boolean): If true, the reference was successfully enabled.

***

### `getAngleTo`

Calculates the angle from this reference's current facing to the target reference.

```lua
local angle = tes3reference:getAngleTo(reference)
```

**Parameters**:

* `reference` ([tes3reference](../../types/tes3reference)): The reference to calculate the angle to.

**Returns**:

* `angle` (number): The angle to the given reference.

***

### `getAttachedDynamicLight`

Fetches the dynamic light attachment.

```lua
local result = tes3reference:getAttachedDynamicLight()
```

**Returns**:

* `result` (tes3lightNode)

***

### `getOrCreateAttachedDynamicLight`

Fetches the dynamic light attachment. If there isn't one, a new one will be created with the given light and value.

If no light is supplied as an argument, a point light of radius 512 will be automatically created.

If the light is not attached to any part of the scene graph yet, the point light will be placed as a child of the "attachLight" subnode of the model, or a child of the model if "attachLight" is not found.

```lua
local result = tes3reference:getOrCreateAttachedDynamicLight(light, phase)
```

**Parameters**:

* `light` ([niPointLight](../../types/niPointLight)): *Optional*.
* `phase` (number): *Optional*.

**Returns**:

* `result` (tes3lightNode)

***

### `onCloseInventory`

A function that tells the game that an inventory has been closed, if you are simulating inventory operations. It has the capability of un-cloning an inventory if it has not been modified. Typically not used outside of specific purposes.

```lua
local result = tes3reference:onCloseInventory()
```

**Returns**:

* `result` (boolean)

***

### `setActionFlag`

Sets a bit in the reference's action data attachment

```lua
tes3reference:setActionFlag(flagIndex)
```

**Parameters**:

* `flagIndex` (number): The action flag to clear.

***

### `setDynamicLighting`

Sets the dynamic lighting state of the reference using the global data handler.

```lua
tes3reference:setDynamicLighting()
```

***

### `setNoCollisionFlag`

Sets if this reference has active collision. This is preferable to the hasNoCollision property, if are manipulating multiple objects at once and do not want to constantly recalculate collision groups.

```lua
tes3reference:setNoCollisionFlag(hasNoCollision, updateCollisions)
```

**Parameters**:

* `hasNoCollision` (boolean): If true, the reference no longer has collision.
* `updateCollisions` (boolean): If true, collision groups for the active cells are recalculated.

***

### `testActionFlag`

Returns the flag's value in the reference's action data attachment

```lua
local result = tes3reference:testActionFlag(flagIndex)
```

**Parameters**:

* `flagIndex` (number): The action flag to clear.

**Returns**:

* `result` (boolean)

***

### `updateEquipment`

Causes the reference, if of an actor, to reevaluate its equipment choices and equip items it should.

```lua
tes3reference:updateEquipment()
```

***

### `updateLighting`

Updates the lighting of the reference using the global data handler.

```lua
tes3reference:updateLighting()
```

***

### `updateSceneGraph`

Updates the reference's local rotation matrix, propagates position changes to the scene graph, and sets the reference's modified flag.

```lua
tes3reference:updateSceneGraph()
```

***

