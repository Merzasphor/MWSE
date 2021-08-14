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

### `references`

*Read-only*. The number of references that exist for the given object. When this value hits zero, the object's memory is freed.

**Returns**:

* `result` (string)

***

### `runTimeTypeInformation`

The runtime type information for this object.

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
local map, index = niTexturingProperty:addDecalMap(texture)
```

**Parameters**:

* `texture` (niTexture): *Optional*. The texture to assign to the new decal.

**Returns**:

* `map` ([niTexturingPropertyMap](../../types/niTexturingPropertyMap), nil): A newly created decal map.
* `index` (number, nil): The index of the newly added decal map.

***

### `clone`

Creates a copy of this object.

```lua
local result = niObject:clone()
```

**Returns**:

* `result` ([niObject](../../types/niObject))

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

### `removeDecalMap`

Attempts to remove a decal at a given index.

```lua
local removed = niTexturingProperty:removeDecalMap(index)
```

**Parameters**:

* `index` (number): The index of the decal to remove.

**Returns**:

* `removed` (boolean): True if the decal was removed.

***

