---
hide:
  - toc
---

# Lighting Modes

!!! tip
	These values are available in Lua by their index in the `ni.lightingMode` table. For example, `ni.lightingMode.emissive` has a value of `0`.

Index       | Value  | Description
----------- | ------ | ----------------
emissive    | `0`    | Only the emissive component of the lighting equation is used. No dynamic lights are considered in the lighting process.
emiAmbDif   | `1`    | The emissive, ambient, and diffuse components of the lighting equation are all used.
