# niCollisionSwitch

An object that specifies if the collision system is enabled.

This type inherits the following: [niNode](../../types/niNode), [niAVObject](../../types/niAVObject), [niObjectNET](../../types/niObjectNET), [niObject](../../types/niObject)
## Properties

### `alphaProperty`

Convenient access to this object's alpha property. Setting this value to be nil will erase the property, while setting it to a valid alpha property will set (or replace) it.

**Returns**:

* `result` ([niAlphaProperty](../../types/niAlphaProperty), nil)

***

### `appCulled`

A flag indicating if this object is culled. When culled, it will not render, and raycasts ignore it.

**Returns**:

* `result` (boolean)

***

### `children`

*Read-only*. The children of the node.

**Returns**:

* `result` ([niAVObject](../../types/niAVObject)[])

***

### `collisionActive`

The enabled state of collision on the collision switch.

**Returns**:

* `result` (boolean)

***

### `controller`

*Read-only*. The first controller available on the object.

**Returns**:

* `result` ([niTimeController](../../types/niTimeController))

***

### `effectList`

*Read-only*. The effect list of the node.

**Returns**:

* `result` ([niDynamicEffectLinkedList](../../types/niDynamicEffectLinkedList))

***

### `extraData`

*Read-only*. The first extra data available on the object.

**Returns**:

* `result` (niExtraData)

***

### `flags`

Flags, dependent on the specific object type.

**Returns**:

* `result` (number)

***

### `fogProperty`

Convenient access to this object's fog property. Setting this value to be nil will erase the property, while setting it to a valid fog property will set (or replace) it.

**Returns**:

* `result` ([niFogProperty](../../types/niFogProperty), nil)

***

### `materialProperty`

Convenient access to this object's material property. Setting this value to be nil will erase the property, while setting it to a valid material property will set (or replace) it.

**Returns**:

* `result` ([niMaterialProperty](../../types/niMaterialProperty), nil)

***

### `name`

The human-facing name of the given object.

**Returns**:

* `result` (string)

***

### `parent`

The object's parent. It may not have one if it is not attached to the scene.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `properties`

The list of properties attached to this `niAVObject`.

**Returns**:

* `result` ([niPropertyLinkedList](../../types/niPropertyLinkedList))

***

### `refCount`

*Read-only*. The number of references that exist for this object. When this value reaches zero, the object will be deleted.

**Returns**:

* `result` (number)

***

### `references`

*Read-only*. The number of references that exist for the given object. When this value hits zero, the object's memory is freed.

**Returns**:

* `result` (string)

***

### `rotation`

The object's local rotation matrix.

**Returns**:

* `result` ([tes3matrix33](../../types/tes3matrix33))

***

### `RTTI`

*Read-only*. The runtime type information for this object. This is an alias for the `.runTimeTypeInformation` property.

**Returns**:

* `result` ([niRTTI](../../types/niRTTI))

***

### `runTimeTypeInformation`

*Read-only*. The runtime type information for this object.

**Returns**:

* `result` ([niRTTI](../../types/niRTTI))

***

### `scale`

The object's local uniform scaling factor.

**Returns**:

* `result` (number)

***

### `stencilProperty`

Convenient access to this object's stencil property. Setting this value to be nil will erase the property, while setting it to a valid stencil property will set (or replace) it.

**Returns**:

* `result` ([niStencilProperty](../../types/niStencilProperty), nil)

***

### `texturingProperty`

Convenient access to this object's texturing property. Setting this value to be nil will erase the property, while setting it to a valid texturing property will set (or replace) it.

**Returns**:

* `result` ([niTexturingProperty](../../types/niTexturingProperty), nil)

***

### `translation`

The object's local translation vector.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `vertexColorProperty`

Convenient access to this object's vertex coloring property. Setting this value to be nil will erase the property, while setting it to a valid vertex coloring property will set (or replace) it.

**Returns**:

* `result` ([niVertexColorProperty](../../types/niVertexColorProperty), nil)

***

### `zBufferProperty`

Convenient access to this object's z-buffer property. Setting this value to be nil will erase the property, while setting it to a valid z-buffer property will set (or replace) it.

**Returns**:

* `result` (niZBufferProperty, nil)

***

## Methods

### `attachChild`

Attachs the child to the children list of the node.

```lua
myObject:attachChild(child, useFirstAvailable)
```

**Parameters**:

* `child` ([niAVObject](../../types/niAVObject))
* `useFirstAvailable` (boolean): *Optional*. Use the first available space in the list. Default value is False.

***

### `attachProperty`

Attach a property to this object.

```lua
myObject:attachProperty(property)
```

**Parameters**:

* `property` ([niProperty](../../types/niProperty))

***

### `clearTransforms`

Resets the object's local transform.

```lua
myObject:clearTransforms()
```

***

### `clone`

Creates a copy of this object.

```lua
local result = myObject:clone()
```

**Returns**:

* `result` ([niObject](../../types/niObject))

***

### `detachChild`

Detaches the child from the children list of the node. Returns the detached child.

```lua
local result = myObject:detachChild(child)
```

**Parameters**:

* `child` ([niAVObject](../../types/niAVObject))

**Returns**:

* `result` ([niAVObject](../../types/niAVObject))

***

### `detachChildAt`

Detaches the child at the specified index from the children list of the node. Returns the detached child.

```lua
local result = myObject:detachChildAt(index)
```

**Parameters**:

* `index` (number)

**Returns**:

* `result` ([niAVObject](../../types/niAVObject))

***

### `detachProperty`

Detaches and returns a property from the object which matches the given property type.

```lua
local result = myObject:detachProperty(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` ([niProperty](../../types/niProperty))

***

### `getEffect`

Gets the effect for the given type.

```lua
local result = myObject:getEffect(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` ([niDynamicEffect](../../types/niDynamicEffect))

***

### `getGameReference`

Searches for an niExtraData on this object to see if it has one that holds a related reference.

```lua
local reference = myObject:getGameReference(searchParents)
```

**Parameters**:

* `searchParents` (boolean): *Default*: `false`. If true, all parent objects (if applicable) are also searched.

**Returns**:

* `reference` ([tes3reference](../../types/tes3reference))

***

### `getObjectByName`

Searches this node and all child nodes recursively for a node with a name that matches the argument.

```lua
local result = myObject:getObjectByName(name)
```

**Parameters**:

* `name` (string)

**Returns**:

* `result` ([niAVObject](../../types/niAVObject))

***

### `getProperty`

Gets an attached property by property type.

```lua
local result = myObject:getProperty(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` ([niProperty](../../types/niProperty))

***

### `isInstanceOfType`

Determines if the object is of a given type, or of a type derived from the given type. Types can be found in the tes3.niType table.

```lua
local result = myObject:isInstanceOfType(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (boolean)

***

### `isOfType`

Determines if the object is of a given type. Types can be found in the tes3.niType table.

```lua
local result = myObject:isOfType(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (boolean)

***

### `prependController`

Add a controller to the object as the first controller.

```lua
myObject:prependController(type)
```

**Parameters**:

* `type` ([niTimeController](../../types/niTimeController))

***

### `removeAllControllers`

Removes all controllers.

```lua
myObject:removeAllControllers()
```

***

### `removeController`

Removes a controller from the object.

```lua
myObject:removeController(controller)
```

**Parameters**:

* `controller` ([niTimeController](../../types/niTimeController))

***

### `saveBinary`

Serializes the object, and writes it to the given file.

```lua
local success = myObject:saveBinary(path)
```

**Parameters**:

* `path` (string): The path to write the file at, relative to the Morrowind installation folder.

**Returns**:

* `success` (boolean): If true the object was successfully serialized.

***

### `setFlag`

Sets a given flag in the niObjectNET flag data. The specifics use of the flag is dependent on the real underlying type.

```lua
myObject:setFlag(state, index)
```

**Parameters**:

* `state` (boolean)
* `index` (number)

***

### `update`

Updates the world transforms of this node and its children, which makes changes visible for rendering. Use after changing any local rotation, translation, scale, or bounds.

```lua
myObject:update()
```

***

### `updateEffects`

Update all attached effects.

```lua
myObject:updateEffects()
```

***

### `updateProperties`

Update all attached properties.

```lua
myObject:updateProperties()
```

***

