---
hide:
  - toc
---

# Particle Bomb Decay Types

!!! tip
	These values are available in Lua by their index in the `ni.particleBombDecayType` table. For example, `ni.particleBombDecayType.none` has a value of `0`.

Index       | Value  | Description
----------- | ------ | ----------------
none        | `0`    | The bomb's force will not decay over distance.
linear      | `1`    | The force will decay linearly with distance.
exponential | `2`    | The force will decay exponentially with distance.
