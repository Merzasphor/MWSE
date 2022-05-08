# niTexturingProperty

A rendering property that controls the methods used to filter texture pixels, and blend texture colors and vertex colors.

This type inherits the following: [niProperty](../../types/niProperty), [niObjectNET](../../types/niObjectNET), [niObject](../../types/niObject)
## Properties

### `applyMode`

The texture apply mode. The texture apply mode controls how the vertex colors are blended with the texture color.

**Returns**:

* `result` (niTexturingPropertyApplyMode)

***

### `baseMap`

Gets or set the base map. Can be set to nil to delete it. Note that doing so will free the memory of the map, causing all existing handles to it to become invalid.

**Returns**:

* `result` ([niTexturingPropertyMap](../../types/niTexturingPropertyMap), nil)

***

### `bumpMap`

Gets or set the bump map. Can be set to nil to delete it. Note that doing so will free the memory of the map, causing all existing handles to it to become invalid.

**Returns**:

* `result` ([niTexturingPropertyMap](../../types/niTexturingPropertyMap), nil)

***

### `canAddDecal`

*Read-only*. If true, the texturing property supports additional decal maps.

**Returns**:

* `result` (boolean)

***

### `controller`

*Read-only*. The first controller available on the object.

**Returns**:

* `result` ([niTimeController](../../types/niTimeController))

***

### `darkMap`

Gets or set the dark map. Can be set to nil to delete it. Note that doing so will free the memory of the map, causing all existing handles to it to become invalid.

**Returns**:

* `result` ([niTexturingPropertyMap](../../types/niTexturingPropertyMap), nil)

***

### `decalCount`

*Read-only*. The number of decals currently on the texturing property.

**Returns**:

* `result` (number)

***

### `detailMap`

Gets or set the detail map. Can be set to nil to delete it. Note that doing so will free the memory of the map, causing all existing handles to it to become invalid.

**Returns**:

* `result` ([niTexturingPropertyMap](../../types/niTexturingPropertyMap), nil)

***

### `extraData`

*Read-only*. The first extra data available on the object.

**Returns**:

* `result` (niExtraData)

***

### `glossMap`

Gets or set the gloss map. Can be set to nil to delete it. Note that doing so will free the memory of the map, causing all existing handles to it to become invalid.

**Returns**:

* `result` ([niTexturingPropertyMap](../../types/niTexturingPropertyMap), nil)

***

### `glowMap`

Gets or set the glow map. Can be set to nil to delete it. Note that doing so will free the memory of the map, causing all existing handles to it to become invalid.

**Returns**:

* `result` ([niTexturingPropertyMap](../../types/niTexturingPropertyMap), nil)

***

### `maps`

The maps of texture property. Accessible as an array.

**Returns**:

* `result` (niTexturingPropertyMapTArray)

***

### `name`

The human-facing name of the given object.

**Returns**:

* `result` (string)

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

### `type`

The unique class identifier number of the given rendering property.

**Returns**:

* `result` (niPropertyType)

***

## Methods

### `addDecalMap`

Attempts to create a new decal map. If successful, it returns both the new map and the index it was created in.

```lua
local map, index = myObject:addDecalMap(texture)
```

**Parameters**:

* `texture` ([niTexture](../../types/niTexture)): *Optional*. The texture to assign to the new decal.

**Returns**:

* `map` ([niTexturingPropertyMap](../../types/niTexturingPropertyMap), nil): A newly created decal map.
* `index` (number, nil): The index of the newly added decal map.

***

### `clone`

Creates a copy of this object.

```lua
local result = myObject:clone()
```

**Returns**:

* `result` ([niObject](../../types/niObject))

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

### `removeDecalMap`

Attempts to remove a decal at a given index.

```lua
local removed = myObject:removeDecalMap(index)
```

**Parameters**:

* `index` (number): The index of the decal to remove.

**Returns**:

* `removed` (boolean): True if the decal was removed.

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

