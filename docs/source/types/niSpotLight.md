# niSpotLight

Represents a spotlight in a scene. Spotlights have a specific location and direction, as well as a distance attenuation and angle attenuation functions. The light direction is handled in the same way as in `niDirectionalLight`.

This type inherits the following: [niPointLight](../../types/niPointLight), [niLight](../../types/niLight), [niDynamicEffect](../../types/niDynamicEffect), [niAVObject](../../types/niAVObject), [niObjectNET](../../types/niObjectNET), [niObject](../../types/niObject)
## Properties

### `affectedNodes`

The list of nodes that a given dynamic effect will affect.

**Returns**:

* `result` (niNodeLinkedList)

***

### `alphaProperty`

Convenient access to this object's alpha property. Setting this value to be nil will erase the property, while setting it to a valid alpha property will set (or replace) it.

**Returns**:

* `result` ([niAlphaProperty](../../types/niAlphaProperty), nil)

***

### `ambient`

The ambient settings for the light.

**Returns**:

* `result` ([niColor](../../types/niColor))

***

### `appCulled`

A flag indicating if this object is culled. When culled, it will not render, and raycasts ignore it.

**Returns**:

* `result` (boolean)

***

### `constantAttenuation`

The constant attenuation factor.

**Returns**:

* `result` (number)

***

### `diffuse`

The defuse settings for the light.

**Returns**:

* `result` ([niColor](../../types/niColor))

***

### `dimmer`

The dimmer settings for the light.

**Returns**:

* `result` ([niColor](../../types/niColor))

***

### `direction`

The direction of the spotlight.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `enabled`

The enabled state of a given dynamic effect.

**Returns**:

* `result` (boolean)

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

### `linearAttenuation`

The linear attenuation factor.

**Returns**:

* `result` (number)

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

### `quadraticAttenuation`

The quadratic attenuation factor.

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

### `specular`

The specular settings for the light.

**Returns**:

* `result` ([niColor](../../types/niColor))

***

### `spotAngle`

The spotlight angle, in degrees.

**Returns**:

* `result` (number)

***

### `spotExponent`

The spotlight angular attenuation exponent. This value may be ignored.

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

### `type`

The enumerated type of a given dynamic effect. Types: `0 - niAmbientLight`, `1 - niDirectionalLight`, `2 - niPointLight`, `3 - niSpotLight`, `4 - niTextureEffect`.

**Returns**:

* `result` (number)

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

### `setAttenuationForRadius`

Sets the attenuation for the radius.

```lua
niPointLight:setAttenuationForRadius(radius)
```

**Parameters**:

* `radius` (number)

***

### `setRadius`

Sets both the light's influence radius, and its lighting attenuation to match the radius.

```lua
niPointLight:setRadius(radius)
```

**Parameters**:

* `radius` (number)

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

## Functions

### `attachAffectedNode`

Adds a node to the dynamic effect's affected nodes list. The node's `:updateEffects()` function should be called afterwards to recognize the change.

```lua
niDynamicEffect.attachAffectedNode(node)
```

**Parameters**:

* `node` ([niNode](../../types/niNode)): The node to add to the affected nodes list.

***

### `detachAffectedNode`

Removes a node from the dynamic effect's affected nodes list. The node's `:updateEffects()` function should be called afterwards to recognize the change.

```lua
niDynamicEffect.detachAffectedNode(node)
```

**Parameters**:

* `node` ([niNode](../../types/niNode)): The node to remove from the affected nodes list.

***

