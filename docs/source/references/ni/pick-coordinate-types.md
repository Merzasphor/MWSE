---
hide:
  - toc
---

# Pick Coordinate Types

!!! tip
	These values are available in Lua by their index in the `ni.pickCoordinateType` table. For example, `ni.pickCoordinateType.worldCoordinates` has a value of `1`.

Index            | Value  | Description
---------------- | ------ | ----------------
modelCoordinates | `0`    | The points returned by picking opertion will be in model coordinates.
worldCoordinates | `1`    | The points returned by picking opertion will be in world coordinates.
