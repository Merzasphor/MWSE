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
	* `texture` (niTexture): *Optional*. If provided, sets the map texture to the given value.
	* `clampMode` (number): *Default*: `WRAP_S_WRAP_T`. The clamp mode to set the map to use.
	* `filterMode` (number): *Default*: `TRILERP`. The filter mode to set the map to use.
	* `textCoords` (number): *Default*: `0`. The texture coordinates to set the map to use.
	* `isBumpMap` (boolean): *Default*: `false`. If true, a bump map will be created instead.

**Returns**:

* `map` ([niTexturingPropertyMap](../../types/niTexturingPropertyMap)): The created basic or bump map.

***

