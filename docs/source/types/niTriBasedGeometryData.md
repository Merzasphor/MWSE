# niTriBasedGeometryData

Contains the actual geometry data for a `NiTriBasedGeometry` object.

This type inherits the following: [niGeometryData](../../types/niGeometryData), [niObject](../../types/niObject)
## Properties

### `bounds`

The bounds of the object.

**Returns**:

* `result` (niBound)

***

### `colors`

*Read-only*. The color for the object.

**Returns**:

* `result` ([niColorA](../../types/niColorA))

***

### `normals`

*Read-only*. The normals list for the object.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

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

### `texCoords`

*Read-only*. The array of texture coordinates.

**Returns**:

* `result` ([tes3vector2](../../types/tes3vector2))

***

### `textures`

*Read-only*. The array of texture coordinates.

**Returns**:

* `result` ([tes3vector2](../../types/tes3vector2))

***

### `textureSets`

The number of texture coordinate sets in the data.

**Returns**:

* `result` (number)

***

### `triangleCount`

The triangle count of the object.

**Returns**:

* `result` (number)

***

### `uniqueID`

A unique ID for this model, assigned at model creation.

**Returns**:

* `result` (number)

***

### `vertexCount`

*Read-only*. The vertex count for the object.

**Returns**:

* `result` (number)

***

### `vertices`

*Read-only*. The array of vertex position data.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

## Methods

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

### `markAsChanged`

Tells the renderer that the object has changed. Should be called after you have finished changing any vertex data.

If you have altered vertex positions, you may need to also call `updateModelBound`_. You should call it if vertices have been moved outside the bounds of the original model.

```lua
niGeometryData:markAsChanged()
```

***

### `updateModelBound`

Updates the geometry bounds to match the vertex data. You should call it if vertices have been moved outside the bounds of the original model, or if the effective bounds have become significantly smaller. 

If you already know the effective radius of the vertex data, you could more efficiently set the bounds directly instead of calling this function.

```lua
niGeometryData:updateModelBound()
```

***

