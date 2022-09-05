---
hide:
  - toc
---

# Gravity Force Types

!!! tip
	These values are available in Lua by their index in the `ni.gravityForceType` table. For example, `ni.gravityForceType.spherical` has a value of `1`.

Index       | Value  | Description
----------- | ------ | ----------------
planar      | `0`    | Gravity of this type operates parallel to the `direction` vector of the niGravity.
spherical   | `1`    | Gravity of this type operates spherically about the `position` point of the niGravity.
