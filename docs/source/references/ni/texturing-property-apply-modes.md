---
hide:
  - toc
---

# Texturing Property Apply Modes

!!! tip
	These values are available in Lua by their index in the `ni.texturingPropertyApplyMode` table. For example, `ni.texturingPropertyApplyMode.replace` has a value of `0`.

In the table below, C~R~ represents the resulting color, A~R~ represents the final alpha. The same notation is used for texture color and alpha values but with index T. Vertex color values have index V.

Index    | Value  | Resulting Color                        | Resulting Alpha    | Common Application
-------- | ------ | -------------------------------------- | ------------------ | -------------------
replace  | `0`    | C~R~ = C~T~                            | A~R~ = A~T~        | Basic texturing without any dynamic or static vertex-based lighting.
decal    | `1`    | C~R~ = C~T~ x A~T~ + C~V~ x (1 - A~T~) | A~R~ = A~V~        | Decal or bullet-hole textures on a base untextured surface.
modulate | `2`    | C~R~ = C~T~ x C~V~                     | A~R~ = A~T~ x A~V~ | Texture and final vertex colors and alpha values are multiplied component-by-component.
