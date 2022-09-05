---
hide:
  - toc
---

# Texturing Property Clamp Modes

!!! tip
	These values are available in Lua by their index in the `ni.texturingPropertyClampMode` table. For example, `ni.texturingPropertyClampMode.wrapSwrapT` has a value of `3`.

Index        | Value  | Description
------------ | ------ | -----------------------------------------------
clampSclampT | `0`    | Both texture dimensions are wrapped infinitely.
clampSwrapT  | `1`    | U dimension is wrapped, V dimension is clamped to be between 0 and 1.
wrapSclampT  | `2`    | U dimension is clamped to be between 0 and 1, V dimension is wrapped.
wrapSwrapT   | `3`    | Both dimensions are clamped to be between 0 and 1.
