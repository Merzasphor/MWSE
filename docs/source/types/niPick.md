# niPick

Class used in the picking intersection system within the game engine.  Using a ray, the engine performs picking operations on a scene graph or any subtree. Given a ray and a subtree, the subtree is traversed and matching nodes are added to an array.

## Properties

### `coordinateType`

The coordinate type for the object.

**Returns**:

* `result` (niPickCoordinateType)

***

### `frontOnly`

If true, back face triangles (those with clockwise winding order) are culled prior to intersection calculations. If false, intersections of ray with triangles are computed regardless of triangle orientation.
    

**Returns**:

* `result` (boolean)

***

### `intersectType`

The intersect type for the object.

**Returns**:

* `result` (niPickIntersectType)

***

### `lastAddedRecord`

The pick record that was last added to the object.

**Returns**:

* `result` ([niPickRecord](../../types/niPickRecord))

***

### `observeAppCullFlag`

If true, the pick stops if it encounters an object with the 'app culled' flag set.  If false, the pick will continue over 'app culled' objects.
    

**Returns**:

* `result` (boolean)

***

### `pickType`

The pick type for the object.

**Returns**:

* `result` (niPickType)

***

### `results`

The array of pick records obtained by the last call to PickObjects.

**Returns**:

* `result` (niPickRecordTArray)

***

### `returnColor`

If true, a vertex color value is returned for the point of intersection of triangles during picking.

**Returns**:

* `result` (boolean)

***

### `returnNormal`

If true, a unit-length normal is returned for the point of intersection of triangles intersected during the picking.

**Returns**:

* `result` (boolean)

***

### `returnSmoothNormal`

If true and if vertex normals exist, then a unit-length normal vector is interpolated from the vertex normals and returned during the picking operation.

**Returns**:

* `result` (boolean)

***

### `returnTexture`

If true, texture coordinates are returned for the point of intersection of triangles during the picking operation.

**Returns**:

* `result` (boolean)

***

### `root`

The root pick type for the object.

**Returns**:

* `result` (niPickType)

***

### `sortType`

The sort type for the object.

**Returns**:

* `result` (niPickSortType)

***

## Methods

### `clearResults`

Clears the results of any previous picking operation.

```lua
niPick:clearResults()
```

***

### `pickObjects`

Performs the picking operation.

```lua
niPick:pickObjects(origin, distance, append, maxDistance)
```

**Parameters**:

* `origin` ([tes3vector3](../../types/tes3vector3))
* `distance` ([tes3vector3](../../types/tes3vector3))
* `append` (boolean): *Optional*. Default value: false
* `maxDistance` (number): *Optional*. Default value: 0.0F

***

