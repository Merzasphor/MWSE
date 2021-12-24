# niSwitchNode

Represents groups of multiple scene graph subtrees, only one of which is visible at any given time. They are useful for showing different states of a model depending on engine / lua logic. If you detach the active subtree, the switch node will set the active subtree to none, or to an index of -1.

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

* `result` (niAVObjectTArray)

***

### `effectList`

*Read-only*. The effect list of the node.

**Returns**:

* `result` ([niDynamicEffectLinkedList](../../types/niDynamicEffectLinkedList))

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

### `runTimeTypeInformation`

The runtime type information for this object.

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

### `switchIndex`

The value of the active child index. This index represents the index of the active child in the array of the NiSwitchNode. If this index is –1, then no child is active.

**Returns**:

* `result` (number)

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
niNode:attachChild(child, useFirstAvailable)
```

**Parameters**:

* `child` ([niAVObject](../../types/niAVObject))
* `useFirstAvailable` (boolean): *Optional*. Use the first available space in the list. Default value is False.

***

### `attachProperty`

Attach a property to this object.

```lua
niAVObject:attachProperty(property)
```

**Parameters**:

* `property` ([niProperty](../../types/niProperty))

***

### `clearTransforms`

Resets the object's local transform.

```lua
niAVObject:clearTransforms()
```

***

### `clone`

Creates a copy of this object.

```lua
local result = niObject:clone()
```

**Returns**:

* `result` ([niObject](../../types/niObject))

***

### `detachChild`

Detaches the child from the children list of the node. Returns the detached child.

```lua
local result = niNode:detachChild(child)
```

**Parameters**:

* `child` ([niAVObject](../../types/niAVObject))

**Returns**:

* `result` ([niAVObject](../../types/niAVObject))

***

### `detachChildAt`

Detaches the child at the specified index from the children list of the node. Returns the detached child.

```lua
local result = niNode:detachChildAt(index)
```

**Parameters**:

* `index` (number)

**Returns**:

* `result` ([niAVObject](../../types/niAVObject))

***

### `detachProperty`

Detaches and returns a property from the object which matches the given property type.

```lua
local result = niAVObject:detachProperty(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` ([niProperty](../../types/niProperty))

***

### `getActiveChild`

Gets the active child node, or returns nil if the switch index is -1.

```lua
local result = niSwitchNode:getActiveChild()
```

**Returns**:

* `result` ([niAVObject](../../types/niAVObject))

***

### `getEffect`

Gets the effect for the given type.

```lua
local result = niNode:getEffect(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` ([niDynamicEffect](../../types/niDynamicEffect))

***

### `getObjectByName`

Searches this node and all child nodes recursively for a node with a name that matches the argument.

```lua
local result = niAVObject:getObjectByName(name)
```

**Parameters**:

* `name` (string)

**Returns**:

* `result` ([niAVObject](../../types/niAVObject))

***

### `getProperty`

Gets an attached property by property type.

```lua
local result = niAVObject:getProperty(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` ([niProperty](../../types/niProperty))

***

### `isInstanceOfType`

Determines if the object is of a given type, or of a type derived from the given type. Types can be found in the tes3.niType table.

```lua
local result = niObject:isInstanceOfType(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (boolean)

***

### `isOfType`

Determines if the object is of a given type. Types can be found in the tes3.niType table.

```lua
local result = niObject:isOfType(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (boolean)

***

### `prependController`

Add a controller to the object as the first controller.

```lua
niObjectNET:prependController(type)
```

**Parameters**:

* `type` ([niTimeController](../../types/niTimeController))

***

### `removeAllControllers`

Removes all controllers.

```lua
niObjectNET:removeAllControllers()
```

***

### `removeController`

Removes a controller from the object.

```lua
niObjectNET:removeController(type)
```

**Parameters**:

* `type` ([niTimeController](../../types/niTimeController))

***

### `update`

Updates the world transforms of this node and its children, which makes changes visible for rendering. Use after changing any local rotation, translation, scale, or bounds.

```lua
niAVObject:update()
```

***

### `updateEffects`

Update all attached effects.

```lua
niAVObject:updateEffects()
```

***

### `updateProperties`

Update all attached properties.

```lua
niAVObject:updateProperties()
```

***

