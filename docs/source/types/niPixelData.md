# niPixelData

Represents 2D arrays of pixel values, as well as pyramids of multiple mipmap levels, each of 2D arrays of pixel values. Also contains information representing the format of the pixels and dimensions of the arrays.

This type inherits the following: [niObject](../../types/niObject)
## Properties

### `bytesPerPixel`

*Read-only*. The number of bytes per pixel.

**Returns**:

* `result` (number)

***

### `mipMapLevels`

*Read-only*. The number of MipMap levels.

**Returns**:

* `result` (number)

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

## Methods

### `clone`

Creates a copy of this object.

```lua
local result = niObject:clone()
```

**Returns**:

* `result` ([niObject](../../types/niObject))

***

### `createSourceTexture`

Creates a source texture from the current NiPixelData object.

```lua
local result = niPixelData:createSourceTexture()
```

**Returns**:

* `result` ([niSourceTexture](../../types/niSourceTexture))

***

### `getHeight`

Returns the height of the mipmap level at the given index, where level 1 is the largest.

```lua
local result = niPixelData:getHeight(mipMapLevel)
```

**Parameters**:

* `mipMapLevel` (number): *Optional*. Default value: 1

**Returns**:

* `result` (number)

***

### `getWidth`

Returns the width of the mipmap level at the given index, where level 1 is the largest.

```lua
local result = niPixelData:getWidth(mipMapLevel)
```

**Parameters**:

* `mipMapLevel` (number): *Optional*. Default value: 1

**Returns**:

* `result` (number)

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

### `setPixelsByte`

Sets the pixel data from byte data.

```lua
niPixelData:setPixelsByte(data, mipMapLevel)
```

**Parameters**:

* `data` (table): The byte data to be set to.
* `mipMapLevel` (number): *Optional*. Default value: 1

***

### `setPixelsFloat`

Sets the pixel data from float data.

```lua
niPixelData:setPixelsFloat(data, mipMapLevel)
```

**Parameters**:

* `data` (table): The float data to be set to.
* `mipMapLevel` (number): *Optional*. Default value: 1

***

## Functions

### `new`

Creates a new NiPixelData object.

```lua
niPixelData.new(width, height)
```

**Parameters**:

* `width` (number)
* `height` (number)

***

