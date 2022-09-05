---
hide:
  - toc
---

# Source Vertex Modes

!!! tip
	These values are available in Lua by their index in the `ni.sourceVertexMode` table. For example, `ni.sourceVertexMode.emissive` has a value of `1`.

Index    | Value  | Description
-------- | ------ | ----------------
ignore   | `0`    | Emissive, ambient, and diffuse colors are all specified by the niMaterialProperty. In other words, vertex colors aren't used.
emissive | `1`    | Emissive colors are specified by the source vertex colors. Ambient and Diffuse are specified by the niMaterialProperty.
ambDiff  | `2`    | Ambient and Diffuse colors are specified by the source vertex colors. Emissive is specified by the niMaterialProperty (Default).
