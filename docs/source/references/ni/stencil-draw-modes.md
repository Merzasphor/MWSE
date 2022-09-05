---
hide:
  - toc
---

# Stencil Draw Modes

!!! tip
	These values are available in Lua by their index in the `ni.stencilDrawMode` table. For example, `ni.stencilDrawMode.counterclockwise` has a value of `1`.

Index                  | Value  | Description
---------------------- | ------ | ----------------
counterclockwiseOrBoth | `0`    | The default mode, chooses between counterclockwise or both.
counterclockwise       | `1`    | Draw only the triangles whose vertices are ordered counter-clockwise with respect to the viewer (Standard behavior).
clockwise              | `2`    | Draw only the triangles whose vertices are ordered clockwise with respect to the viewer (Effectively flips the faces).
both                   | `3`    | Do not cull back faces of any kind. Draw all triangles, regardless of orientation (Effectively force double-sided).
