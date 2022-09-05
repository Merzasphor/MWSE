---
hide:
  - toc
---

# Particle Bomb Symmetry Types

!!! tip
	These values are available in Lua by their index in the `ni.particleBombSymmetryType` table. For example, `ni.particleBombSymmetryType.cylindrical` has a value of `1`.

Index       | Value  | Description
----------- | ------ | ----------------
spherical   | `0`    | The bomb's force will operate spherically about the point specified by `position` vector.
cylindrical | `1`    | The bomb will apply force to particles perpendicular to the `direction` vector but centered about the `position` vector.
planar      | `2`    | The bomb's force is applied parallel to the `direction` vector.
