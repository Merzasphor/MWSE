# niTexturingPropertyMap

A combination of a texture, a filter mode, a clamping mode, and an index to a set of texture coordinates.

## Properties

### `clampMode`

The clamp mode for the Map.

**Returns**:

* `result` (niTexturingPropertyClampMode)

***

### `filterMode`

The filter mode for the Map.

**Returns**:

* `result` (niTexturingPropertyFilterMode)

***

### `texCoordSet`

The texture coordinate set for the Map.

**Returns**:

* `result` (number)

***

### `texture`

The texture for the Map.

**Returns**:

* `result` (niTexture)

***

## Functions

### `new`

Creates a new basic or bump map.

```lua
local map = niTexturingPropertyMap.new({ texture = ..., clampMode = ..., filterMode = ..., textCoords = ..., isBumpMap = ... })
```

**Parameters**:

* `params` (table)
	* `texture` (niTexture): If provided, sets the map texture to the given value.
	* `clampMode` (number): The clamp mode to set the map to use.
	* `filterMode` (number): The filter mode to set the map to use.
	* `textCoords` (number): The texture coordinates to set the map to use.
	* `isBumpMap` (boolean): If true, a bump map will be created instead.

**Returns**:

* `map` ([niTexturingPropertyMap](../../types/niTexturingPropertyMap)): The created basic or bump map.

***

